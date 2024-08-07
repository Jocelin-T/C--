#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>
#include <condition_variable>

/* NOTES:
    1. std::promise
        a. Used to set values or exceptions.
    2. std::future
        a. Used to get values from promise.
        b. Ask promise if the value is available.
        c. Wait for the promise
*/

typedef long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end){
    ull OddSum{ 0 };
    for (ull i = start; i<= end; ++i){
        if (i & 1){
            OddSum += 1;
        }
    }
    OddSumPromise.set_value(OddSum); // Set the value inside the promise
}

int main(){
    ull start{0}, end{1900000000};

    std::promise<ull> OddSum; // First create a promise 
    std::future<ull> OddFuture = OddSum.get_future(); // Then create a future of that promise
    
    std::cout << "Thread Created!" << "\n";
    std::thread t1(findOdd, std::move(OddSum), start, end);

    std::cout << "Waiting for result" << "\n";

    std::cout << "OddSum: " << OddFuture.get() << "\n"; // The future wait until the promise is complete

    std::cout << "Completed" << std::endl;
    t1.join();

    return 0;
}