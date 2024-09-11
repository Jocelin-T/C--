#include <iostream>
#include <functional> // Needed for std::function

// #################################### Function Pointers ####################################

// Function ptr with typedef: typedef type (*pFnFunctionName)(type, type)
// pFn as prefix for: pointer Function
typedef int (*pFnIntOperatorTypeDef)(int, int);

int add(int x, int y){
    return x + y;
}

int multiply(int x, int y){
    return x * y;
}

int main() {
    // **** Basic C++ ****//
    // function pointer for any functions who are composed of: type functionName(type, type);
    // int (*intOperator)(int, int);

    // **** Modern C++ ****//
    // Function pointer with std::function (need #include <functional>)
    std::function<int(int, int)> intOperator;

    // **** Typedef ****//
    // Function pointer with typedef (need a typedef before, can be in the header file)
    // pFnIntOperatorTypeDef intOperator;

    std::cout << "[1] for Add or [2] for Multiply\n";
    int n{0};
    std::cin >> n;
    if (n == 1){
        intOperator = add; // point to the function when we want
    }
    else if (n == 2){
        intOperator = multiply; // point to the function when we want
    }
    else {
        std::cout << "Error\n";
    }

    std::cout << "Choose your numbers: ";
    int x, y;
    std::cin >> x;
    std::cin >> y;
    std::cout << "Add: " << intOperator(x, y) << "\n"; // the selected function is call there

    return 0;
}