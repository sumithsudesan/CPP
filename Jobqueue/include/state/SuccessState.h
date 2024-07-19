#ifndef SUCCESSSTATE_H
#define SUCCESSSTATE_H

#include "JobState.h"

// Success state
class SuccessState : public JobState {
    public:
        // Manages the Success State
        void handle(Job& job) override;
};

#endif
