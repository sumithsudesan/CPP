#include "SuccessState.h"
#include "CleanupState.h"
#include "Job.h"

// Success State handle
void SuccessState::handle(Job& job) {
    // Transition to cleanup state
    job = std::make_shared<CleanupState>();
}
