#ifndef RUNNINGSTATE_H
#define RUNNINGSTATE_H

#include "JobState.h"

// Job Running State
class RunningState : public JobState {
    public:
        // Manages the Running State
        void handle(Job& job) override;
};

#endif
