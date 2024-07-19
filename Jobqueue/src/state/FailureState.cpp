#include "FailureState.h"
#include "Job.h"
#include "CleanupState.h"


// Failure State Handle
void FailureState::handle(Job& job) {
    // Handle job failure and transition to CleanupState
    job.setState(std::make_shared<CleanupState>());
}
