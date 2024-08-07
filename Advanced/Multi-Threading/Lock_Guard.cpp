#include <iostream>
#include <thread>
#include <mutex>

// Global variable shared among threads
int buffer = 0;

// Mutex to protect the critical section
std::mutex mtx;

// Function to be run by each thread
void task(const std::string& threadName) {
    // lock_guard acquires the mutex lock when created
    std::lock_guard<std::mutex> lock(mtx);
    
    // Critical section starts
    for(int i = 0; i < 10; ++i) {
        ++buffer; // Increment the shared variable
        std::cout << threadName << " incremented buffer to " << buffer << std::endl;
    }
    // Critical section ends when lock goes out of scope and automatically releases the mutex
}

int main() {
    // Create two threads that run the task function
    std::thread t1(task, "Thread 1");
    std::thread t2(task, "Thread 2");
    
    // Wait for both threads to finish execution
    t1.join();
    t2.join();
    
    // Print the final value of the shared variable
    std::cout << "Final buffer value: " << buffer << std::endl;
    
    return 0;
}
