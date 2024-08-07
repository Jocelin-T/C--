#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

/* IMPORTANT POINT: CV are used for two purpose
    A. Notifiy other threads
    B. Waiting for some conditions

    1. Condition Variable allows running threads to wait on some conditions and once those
     conditions are met the waiting thread is notified using:
        a. notify_one();
        b. notify_all();
    2. You need mutex to use condition variable
    3. If some thread want to wait on some condition then it has to do these things:
        a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);
        b. Execute wait, wait for or wait_until. The wait operations automatically release the mutex
            and suspend the execution of the thread.
        c. When the condition variable is notified, the thread is awakened and the mutex is automatically reacquired.
            The thread should then check the condition and resume waiting if the wake up was spurious(fake)

    NOTE:
    1. Condition variables are used to synchronize two or more threads.
    2. Best use case of condition vaiable is Producer/Consumer problem.
*/


// Shared resources
std::mutex mtx;                 // Mutex to protect shared resources
std::condition_variable cv;     // Condition variable to synchronize threads
int balance = 0;                // Shared balance variable

// Function to add money to the balance
void addMoney() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate some work
    std::lock_guard<std::mutex> lg(mtx);                 // Lock the mutex
    balance += 500;                                      // Add 500 to the balance
    std::cout << "Amount added. Current balance: " << balance << std::endl;
    cv.notify_one();                                     // Notify one waiting thread
}

// Function to withdraw money from the balance
void withdrawMoney(int amount) {
    std::unique_lock<std::mutex> ul(mtx);                // Lock the mutex with unique_lock
    cv.wait(ul, []{ return balance != 0; });             // Wait until balance is not zero
    if(balance >= amount) {                              // Check if balance is sufficient
        balance -= amount;                               // Withdraw the amount
        std::cout << "Amount withdrawn: " << amount << ". Current balance: " << balance << std::endl;
    } else {                                             // If balance is insufficient
        std::cout << "Amount cannot be withdrawn. Current balance is less than " << amount << std::endl;
    }
}

// Main function
int main() {
    std::thread t1(withdrawMoney, 500);                  // Start withdrawMoney thread
    std::thread t2(addMoney);                            // Start addMoney thread

    t1.join();                                           // Wait for withdrawMoney thread to finish
    t2.join();                                           // Wait for addMoney thread to finish

    return 0;
}
