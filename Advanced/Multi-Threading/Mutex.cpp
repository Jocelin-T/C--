#include <iostream>
#include <thread>
#include <mutex>

int myAmount = 0;
// Mutex to protect the critical section
std::mutex mtx;

// Function to be run by each thread
void addMoney() {
    // Lock the mutex before entering the critical section
    mtx.lock();
    
    // Critical section starts
    // Simulating some work by the thread
    for(int i = 0; i < 100000; ++i) {
        ++myAmount; // Increment the shared variable
    }
    // Unlock the mutex after leaving the critical section
    mtx.unlock();
}

int main() {
    // Create two threads that run the addMoney function
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    
    // Wait for both threads to finish execution
    t1.join();
    t2.join();
    
    // Print the final value of the shared variable
    std::cout << "Final Amount: " << myAmount << std::endl;
    
    return 0;
}
