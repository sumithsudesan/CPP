#include "WaitingState.h"
#include "Job.h"
#include "ThreadPool.h"
#include "RunningState.h"

// Waiting State handle
void WaitingState::handle(Job& job) {
    // Here, you would typically check if threads are available and then move to RunningState
    // For simplicity, we'll transition directly
    job.setState(std::make_shared<RunningState>());
}
