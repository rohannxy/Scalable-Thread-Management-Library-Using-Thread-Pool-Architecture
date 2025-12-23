#include "thread_pool.h"

ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&ThreadPool::workerThread, this);
    }
}

void ThreadPool::workerThread() {
    while (!stop) {
        std::function<void()> task;
        if (taskQueue.pop(task)) {
            task();
        }
    }
}

void ThreadPool::submit(std::function<void()> task) {
    taskQueue.push(task);
}

ThreadPool::~ThreadPool() {
    stop = true;
    for (size_t i = 0; i < workers.size(); ++i) {
        taskQueue.push([] {});
    }
    for (auto& t : workers) {
        if (t.joinable())
            t.join();
    }
}
