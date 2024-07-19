#include "InitializationState.h"
#include "Job.h"

// Initialization State handle
void InitializationState::handle(Job& job) {
    // Transition to WaitingState
    job.setState(std::make_shared<WaitingState>());
}
