#ifndef JOBSTATE_H
#define JOBSTATE_H

#include <memory>

// Job 
class Job;

// Job state interface
class JobState {
    public:
        // Destructor
        virtual ~JobState() = default;
        // Handles Operator
        virtual void handle(Job& job) = 0;
};

#endif
