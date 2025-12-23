#include "task_queue.h"

void TaskQueue::push(std::function<void()> task) {
    std::unique_lock<std::mutex> lock(mtx);
    tasks.push(task);
    cv.notify_one();
}

bool TaskQueue::pop(std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(mtx);

    while (tasks.empty()) {
        cv.wait(lock);
    }

    task = tasks.front();
    tasks.pop();
    return true;
}
