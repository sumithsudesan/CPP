#include <iostream>
#include <memory>
#include <thread>
#include <atomic>
#include <future>
#include "ThreadPool.h"
#include "JobQueue.h"
#include "Job.h"
#include "States/InitializationState.h"

// Handles the process job
void processJob(std::shared_ptr<Job> jobPtr, 
                JobQueue& jobQueue) {
    auto jobToProcessPtr = jobQueue.pop();
    jobToProcessPtr->execute();
}

// Enqueue a job and signal completion
void enqueueJob(ThreadPool& JobThreadPool, 
                JobQueue& jobQueue, 
                std::shared_ptr<Job> jobPtr,
                std::atomic<int>& nJobsRemaining) {
    JobThreadPool.enqueue([jobPtr, &jobQueue, &jobsRemaining]() {
        processJob(jobPtr, jobQueue);
        // Decrement the count of remaining jobs
        --nJobsRemaining;
    });
}

int main() {
    std::cout << "[INFO] Jobs Queue" << std::endl;

    // Job count
    const int nNumJobs = 10;

    // Thread  count in thread pool
    ThreadPool pool(4);

    // Job Queue
    JobQueue jobQueue;

    // Manages number of remaining job
    std::atomic<int> nJobsRemaining(nNumJobs);

    // Create a promise to signal completion
    std::promise<void> allJobsDonePromise;
    std::future<void> allJobsDoneFuture = allJobsDonePromise.get_future();

    // Jobs
    for (int i = 0; i < nNumJobs; ++i) {
        auto jobPtr = std::make_shared<Job>(static_cast<Job::JobID>(i));
        jobPtr->setState(std::make_shared<InitializationState>());

        jobQueue.push(jobPtr);

        // Enqueue job processing task
        enqueueJob(pool, jobQueue, jobPtr, nJobsRemaining);
    }

    // Lambda to check if all jobs are done
    auto checkCompletion = [&nJobsRemaining, &allJobsDonePromise]() {
        while (nJobsRemaining > 0) {
            // Polling interval
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
        }
        allJobsDonePromise.set_value();
    };

    // Start a thread to monitor job completion
    std::thread completionThread(checkCompletion);
    
    // Wait for the final signal that all jobs are done
    allJobsDoneFuture.wait();

    if (completionThread.joinable()) {
        completionThread.join();
    }

    std::cout << "[INFO] Jobs have been processed." << std::endl;
    return 0;
}
