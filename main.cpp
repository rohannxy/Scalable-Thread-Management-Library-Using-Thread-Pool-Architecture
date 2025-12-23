#include <iostream>
#include <thread>
#include "thread_pool.h"

int main() {
    ThreadPool pool(4);

    for (int i = 0; i < 20; i++) {
        pool.submit([i]() {
            std::cout << "Task " << i
                      << " running on thread "
                      << std::this_thread::get_id()
                      << std::endl;
        });
    }

    std::cin.get(); // keeps console open
    return 0;
}
