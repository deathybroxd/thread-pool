#include "include/ThreadPool.h"

int task;

/* void NumTest() {
    std::cout << "TASK: " << task << " | THREAD ID: " << std::this_thread::get_id() << std::endl;
    task++;
    // 32 is just the num of threads on my i9-14900hx cpu
    std::cout << "printing 32 nums: " << std::endl;
    for(int i = 0; i < 32; ++i) {
        std::cout << i << std::endl;
    }
} */

void BraindeadTest() {
    std::cout << "TASK: " << task << " | THREAD ID: " << std::this_thread::get_id() << std::endl;
    task++;
    std::vector<int> nums;
    for(size_t i = 0; i < 1000; ++i) {
        nums.push_back(i);
    }
}

void BraindeadTest2() {
    std::cout << "TASK: " << task << " | THREAD ID: " << std::this_thread::get_id() << std::endl;
    task++;
    std::vector<std::string> lotsOfA;
    for(size_t i = 0; i < 1000; ++i) {
        lotsOfA.push_back("A");
    }
}



int main() {
    // get the actual number of threads from the users cpu
    unsigned int numThreads = std::thread::hardware_concurrency();

    // fallback number if fail
    if(numThreads == 0) {
        numThreads = 4;
    }

    ThreadPool pool(numThreads);
    /* std::cout << "basic num test: " << std::endl;
    pool.Submit(NumTest); 
    std::cout << "braindead tests: " << std::endl; */

    // this takes about like 2 minutes on an i9-14900hx, 20k tasks
    for(int i = 0; i < 10000; ++i) {
        pool.Submit(BraindeadTest);
        pool.Submit(BraindeadTest2);
    }


    return 0;
}