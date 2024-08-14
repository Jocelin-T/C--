#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm> // std::for_each


// #################################### Capture in lambda function ####################################
// Notes:   Capture is what is inside [], who are variable passed by copy or reference


int main(){

    std::vector<int> v{1,3,2,5,9};
    int last_result{0};
    int last_result_2{0};

    // Capture explicit variables by reference.
    auto print_v = [&last_result, &last_result_2](int n)->void{
        last_result_2 = last_result;
        last_result = n;
        std::cout << n << "\n"; 
    };

    // Capture by the compiler by reference (use if lambda is simple).
    auto print_a = [&](int n)->void{
        last_result_2 = last_result;
        last_result = n;
        std::cout << n << "\n"; 
    };

    // Capture by the compiler by copy (use if lambda is simple).
    // Need to be mutable if reassignment.
    auto print_a2 = [=](int n)mutable->void{
        last_result_2 = last_result;
        last_result = n;
        std::cout << n << "\n"; 
    };

    // Capture a copy won't work if there is a reassignment.
    auto print_b = [last_result](int n)->void{
        // last_result = n; // reassignment don't work
        std::cout << last_result << "\n"; // read-only work
        std::cout << n << "\n"; 
    };

    // It will be possible with the keyword mutable after the params,
    //  and before the return type.
    auto print_c = [&last_result](int n) mutable->void{
        last_result = n;
        std::cout << n << "\n"; 
    };

    std::for_each(std::begin(v),
                std::end(v),
                print_v
    );
    
    std::cout << last_result << "\n";
    std::cout << last_result_2 << "\n";

    return 0;
}