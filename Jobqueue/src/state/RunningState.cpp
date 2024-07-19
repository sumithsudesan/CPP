#include "RunningState.h"
#include "Job.h"
#include "SuccessState.h"
#include "FailureState.h"

// Running State handle
void RunningState::handle(Job& job) {
    // Simulate job execution
    bool bSuccess = true;
    if (bSuccess) {
        job.setState(std::make_shared<SuccessState>());
    } else {
        job.setState(std::make_shared<FailureState>());
    }
}
