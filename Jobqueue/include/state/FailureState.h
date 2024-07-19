#ifndef FAILURESTATE_H
#define FAILURESTATE_H

#include "JobState.h"

// Job Failure State
class FailureState : public JobState {
    public:
        // Handle Job Failure State
        void handle(Job& job) override;
};

#endif 
