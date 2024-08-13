#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm> // std::for_each

// #################################### Lambdas ####################################
// Notes:   Lambdas are unnamed function object (functor) capable of 
//           capturing variable in scope.
//          Avoid useless writing and naming of functions
//          Here how lambda function is write: [captures] (params) {body}

// Lambda is the same as this functor
struct print_functor{
    int m_last_result{0}; // this is [captures]
    void operator()(int n){ // this is (params)
        m_last_result = n; // this is {body}
        std::cout << n << "\n"; // this is {body}
    }
};

int main(){

    std::vector<int> v{1,3,2,5,9};
    int last_result{0};

    // Write directly in a function (here a for each loop, use algorithm)
    std::for_each(std::begin(v),
                std::end(v),
                [&last_result](int n){ last_result = n; std::cout << n << "\n"; }); // this is lambda
    
    // Write as a variable, this is lambda.
    auto print_v = [&last_result](int n){ last_result = n; std::cout << n << "\n"; };
    // this is lambda with a return type (-> void).
    auto print_a = [&last_result](int n)-> void{ last_result = n; std::cout << n << "\n"; };

    std::cout << last_result << "\n";

    return 0;
}