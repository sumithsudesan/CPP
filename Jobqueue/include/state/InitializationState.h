#ifndef INITIALIZATIONSTATE_H
#define INITIALIZATIONSTATE_H

#include "JobState.h"

// Job Initialisation State
class InitializationState : public JobState {
    public:
        // Handle Job Initialisation State
        void handle(Job& job) override;
};

#endif 
