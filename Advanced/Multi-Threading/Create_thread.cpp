#include <iostream>
#include <thread>

// ######################### Function pointer #########################
void function(int n) {
    for (int i = n; i >= 0; --i) {
        std::cout << i << "\n";
    }
}

int main() {
    std::thread t1(function, 10);
    t1.join();
    return 0;
}

// ######################### Lambda #########################
// int main() {
//     auto lambda = [](int n) {
//         for (int i = n; i >= 0; --i) {
//             std::cout << i << "\n";
//         }    
//     };
    
//     std::thread t1(lambda, 10);
//     t1.join();

//     // Alternatively, directly inject lambda during thread creation
//     std::thread t2([](int n) {
//         for (int i = n; i >= 0; --i) {
//             std::cout << i << "\n";
//         }
//     }, 10);
//     t2.join();
    
//     return 0;
// }

// ######################### Functor (function object) #########################
// class Functor {
// public:
//     void operator()(int n) {
//         for (int i = n; i >= 0; --i) {
//             std::cout << i << "\n";
//         }
//     }
// };

// int main() {
//     Functor functor;
//     std::thread t1(functor, 10);
//     t1.join();
//     return 0;
// }

// ######################### Non-Static Member Function #########################
// class Base {
// public:
//     void run(int n) {
//         for (int i = n; i >= 0; --i) {
//             std::cout << i << "\n";
//         }
//     }
// };

// int main() {
//     Base base;
//     std::thread t1(&Base::run, &base, 10);
//     t1.join();
//     return 0;
// }

// ######################### Static Member Function #########################
// class Base {
// public:
//     static void run(int n) {
//         for (int i = n; i >= 0; --i) {
//             std::cout << i << "\n";
//         }
//     }
// };

// int main() {
//     std::thread t1(&Base::run, 10);
//     t1.join();
//     return 0;
// }