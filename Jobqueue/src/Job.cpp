#include "Job.h"
#include "JobState.h"

// Job 
Job::Job(JobID id) : m_Id(id), m_statePtr(nullptr) {}

// Set the state
void Job::setState(std::shared_ptr<JobState> statePtr) {
    this->m_statePtr = statePtr;
}

// Job execute
void Job::execute() {
    if (m_statePtr) {
        m_statePtr->handle(*this);
    }
}

// Get the job id
Job::JobID Job::getID() const {
    return m_Id;
}

// Get the job state
std::shared_ptr<JobState> Job::getState() const {
    return m_statePtr;
}
