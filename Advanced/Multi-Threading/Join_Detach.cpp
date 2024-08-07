#include <iostream>
#include <thread>
#include <chrono>

// Function to be executed by the thread
void run(int count) {
    while (count-- > 0) {
        std::cout << "Thread running, count: " << count << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work by sleeping
    }
    std::cout << "Thread finished execution." << std::endl;
}

int main() {
    // Creating a thread
    std::thread t1(run, 5);

    // Using join to wait for the thread to finish
    if (t1.joinable()) {
        t1.join(); // Wait for the thread to complete
    }

    std::cout << "Main thread after join." << std::endl;

    // Creating another thread
    std::thread t2(run, 5);

    // Using detach to allow the thread to run independently
    if (t2.joinable()) {
        t2.detach(); // Detach the thread
    }

    std::cout << "Main thread after detach." << std::endl;

    // Adding sleep to ensure the detached thread has time to run before main thread exits
    std::this_thread::sleep_for(std::chrono::seconds(6));

    // Reminder: either join or detach should be called to avoid program termination in thread destructor
    std::thread t3(run, 5);
    if (t3.joinable()) {
        t3.detach(); // Ensure t3 is either joined or detached
    }

    std::cout << "Main thread end." << std::endl;

    return 0;
}
