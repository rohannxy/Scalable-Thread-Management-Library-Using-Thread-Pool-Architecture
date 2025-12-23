#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <thread>
#include <atomic>
#include <functional>
#include "task_queue.h"

class ThreadPool {
private:
    std::vector<std::thread> workers;
    TaskQueue taskQueue;
    std::atomic<bool> stop;

    void workerThread();

public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();

    void submit(std::function<void()> task);
};

#endif
