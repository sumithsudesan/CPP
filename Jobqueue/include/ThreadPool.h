#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <atomic>
#include <mutex>
#include <condition_variable>

// Manages the threadpool
class ThreadPool {
    public:
        // Thread pool constructor
        ThreadPool(size_t);
        // Destructor
        ~ThreadPool();
        // Enquque
        void enqueue(std::function<void()>);

    private:
        // Worker Thread list
        std::vector<std::thread> m_Morkers;
        // Tasks queue
        std::queue<std::function<void()>> m_tasksQueue;
        // Mutex
        std::mutex m_Mutex;
        // Condition varibale
        std::condition_variable m_ConVar;
        // Stop
        std::atomic<bool> m_Stop;
};

#endif
