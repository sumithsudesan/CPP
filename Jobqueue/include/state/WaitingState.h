#ifndef WAITINGSTATE_H
#define WAITINGSTATE_H

#include "JobState.h"

// Waiting state
class WaitingState : public JobState {
    public:
        // Manages the Waiting State
        void handle(Job& job) override;
};

#endif
