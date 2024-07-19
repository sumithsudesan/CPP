#ifndef JOB_H
#define JOB_H

#include <memory>
#include "JobState.h"

// Job - Manages the job
class Job {
    public:
        // Job Id 
        enum class JobID { JOB1, JOB2, JOB3 }; 

        // Constructor
        Job(JobID id);

        // Handles set state
        void setState(std::shared_ptr<JobState> statePtr);

        // Manages the operation
        void execute();

        //  Get Job id
        JobID getID() const;

        // Get the current state
        std::shared_ptr<JobState> getState() const;

    private:
        // Handles the job id
        JobID m_Id;

        // Manages the job state
        std::shared_ptr<JobState> m_statePtr;
};

#endif
