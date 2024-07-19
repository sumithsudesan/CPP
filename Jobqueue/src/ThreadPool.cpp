#include "ThreadPool.h"


// Thread pool constructor
ThreadPool::ThreadPool(size_t nNumThreads) : m_Stop(false) {
    for (size_t i = 0; i < nNumThreads; ++i) {
        m_Morkers.emplace_back([this] {
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(m_Mutex);
                    m_ConVar.wait(lock, [this] { return m_Stop || !m_tasksQueue.empty(); });
                    if (m_Stop && m_tasksQueue.empty()) return;
                    task = std::move(m_tasksQueue.front());
                    m_tasksQueue.pop();
                }
                task();
            }
        });
    }
}

// Destructor
ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(m_Mutex);
        m_Stop = true;
    }
    m_ConVar.notify_all();
    for (std::thread &worker : m_Morkers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

// Handles the Enqueue
void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (m_Stop) throw std::runtime_error("enqueue on stopped ThreadPool");
        tasks.emplace(std::move(task));
    }
    m_ConVar.notify_one();
}
