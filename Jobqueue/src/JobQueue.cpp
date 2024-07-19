#include "JobQueue.h"

// Add Job to the queue
void JobQueue::push(std::shared_ptr<Job> jobPtr) {
    std::unique_lock<std::mutex> lock(m_mtx);
    m_JobQueue.push(jobPtr);
    m_ConVar.notify_one();
}

// Gets the job from queue
std::shared_ptr<Job> JobQueue::pop() {
    std::unique_lock<std::mutex> lock(m_mtx);
    m_ConVar.wait(lock, [this] { return !m_JobQueue.empty(); });
    auto jobPtr = m_JobQueue.front();
    m_JobQueue.pop();
    return jobPtr;
}
