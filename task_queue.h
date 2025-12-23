#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class TaskQueue {
private:
    std::queue<std::function<void()>> tasks;
    std::mutex mtx;
    std::condition_variable cv;

public:
    void push(std::function<void()> task);
    bool pop(std::function<void()>& task);
};

#endif
