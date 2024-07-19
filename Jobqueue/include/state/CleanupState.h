#ifndef CLEANUPSTATE_H
#define CLEANUPSTATE_H

#include "JobState.h"

// Job Cleanup State
class CleanupState : public JobState {
    public:
    // Manages Job Cleanup State
    void handle(Job& job) override;
};

#endif 
