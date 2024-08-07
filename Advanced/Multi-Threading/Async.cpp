#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>
#include <condition_variable>


/* NOTES:
    1. It runs a  function asynchronously (potentially in a new thread) and returns a std::future
        that will hold the result.
    2. There are three launch policies for creating task:
        a. std::launch::async
        b. std::launch::deffered
        c. std::launch::async | std::launch::deffered

    HOW IT WORKS:
    1. It automatically creates a thread (Or picks from internal thread pool) and a promise object for us.
    2. Then passes the std::promise object to thread function and returns the associated std::future object.
    3. When our passes argument function exits then is value will be set in this promise object,
        so eventually return value will be available in std::future object.

    SIDE NOTES:
    1. We can send functor and lambda function as callback to std::async, it will work the same.
*/

typedef long int ull;

ull findOdd(ull start, ull end){
    ull OddSum{ 0 };
    for (ull i = start; i<= end; ++i){
        if (i & 1){
            OddSum += 1;
        }
    }
    return OddSum; // return the value
}

int main(){
    ull start{0}, end{1900000000};

    std::cout << "Thread created if policy is std::launch::async" << "\n";
    // std::launch::async will create a new task (so a new thread)
    std::future<ull> OddSum = std::async(std::launch::async, findOdd, start, end);
    
    // std::launch::deferred will create a entry for a new task (NOT a new thread, here it will still run in main thread)
    std::future<ull> OddSum = std::async(std::launch::deferred, findOdd, start, end);
    
    std::cout << "Waiting for result" << "\n";
    std::cout << "OddSum: " << OddSum.get() << "\n";

    std::cout << "Completed" << std::endl;

    return 0;
}