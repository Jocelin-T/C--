#include <iostream>

// #################################### Function Template ####################################
// !!! Don't work if function is after "main()", even with function declaration!!!
template <typename T> // template creation, only 1 type is accepted here
T max(T x, T y){
    return (x > y) ? x : y;
}
template <typename T, typename U> // template with multi type
auto min(T x, U y){ // auto is needed, and the correct type for the variable
    return (x > y) ? x : y;
}
int main(){
// function template =  describes what a function looks like.
//                      Can be used to generate as many overloaded functions
//                      as needed, each using different data types

    std::cout << "int: " << max(1, 2) << "\n";
    std::cout << "double: " << max(1.1, 2.1) << "\n";
    std::cout << "char: " << max('1', '2') << "\n";

    std::cout << "auto: " << min('1', 2.2) << "\n"; // return 49 because ASCCI

    return 0;
}
