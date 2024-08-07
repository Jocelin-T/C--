#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>
#include <map>
#include <queue>

class Salary {
public:
    Salary(int value, std::string str)
    : m_value{value}, m_str{str}
    {
        std::cout << "Thread start\n";
        std::this_thread::sleep_for(std::chrono::seconds(m_value));
        std::cout << "Thread done!\n";
    }

    int getValue() const { return m_value; }
    std::string getStr() const { return m_str; }

private:
    int m_value{0};
    std::string m_str{""};
};

std::mutex mtx;
std::condition_variable cv;
std::queue<Salary> salaryQueue;
bool done = false;

// Creation of Salary objects and adding to the queue
void CreateVectorOfSalary(int value, const std::string& str) {
    for (int i = 0; i < 10; ++i) {
        {
            Salary salary(i, str);
            std::unique_lock<std::mutex> lock(mtx);
            salaryQueue.push(std::move(salary));
        }
        cv.notify_one();
    }

    {
        std::unique_lock<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_one();
    std::cout << "Vector creation done" << std::endl;
}

// Calculate the total value from the queue
void GetTotalValue(std::map<std::string, int>& map) {
    int total{0};

    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !salaryQueue.empty() || done; });

        while (!salaryQueue.empty()) {
            Salary salary = std::move(salaryQueue.front());
            salaryQueue.pop();
            total += salary.getValue();
            std::cout << "Total value: " << total << std::endl;
        }

        if (done && salaryQueue.empty()) {
            break;
        }
    }

    map["total"] = total;
}

int main() {
    std::map<std::string, int> map;

    std::thread t1(CreateVectorOfSalary, 1, "abc");
    std::thread t2(GetTotalValue, std::ref(map));

    t1.join();
    t2.join();

    std::cout << "Final value: " << map["total"] << std::endl;

    return 0;
}
