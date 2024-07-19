#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include "Job.h"


// Manages the job queue
class JobQueue {
    public:
        // Add to the job queue
        void push(std::shared_ptr<Job> job);

        // Gets from job queue
        std::shared_ptr<Job> pop();

    private:
        // Job queue
        std::queue<std::shared_ptr<Job>> m_JobQueue;

        // Mutex
        std::mutex m_mtx;

        //
        std::condition_variable m_ConVar;
};

#endif 
