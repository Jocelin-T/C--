#include <iostream>
#include <cmath>

// #################################### Template Function full or partial specialization ####################################
// Notes:   Float and double data type need absolut for comparison.
//          It's possible to "override" for specific reason.
//          There is no template arguments and data type NEED to be indicate for specialization.

// Don't work in case it's a float data type
template<typename T> 
bool Equal(T x, T y){
    std::cout << "Function Equal: ";
    return (x == y);
}

// ****** For float ****** //
template<>
bool Equal<float>(float x, float y){
    std::cout << "Function Equal<float>: ";
    return fabs(x - y) < 0.00001f;
}

// ****** For double ****** //
template<>
bool Equal<double>(double x, double y){
    std::cout << "Function Equal<double>: ";
    return fabs(x - y) < 0.000000001f;
}

int main(){

    std::cout << Equal<int>(2, 2) << "\n"; // true
    std::cout << Equal<int>(2, 3) << "\n"; // false

    std::cout << Equal<float>(1.0f - 0.999999f, 0.000001f) << "\n"; // true
    std::cout << Equal<float>(1.0f, 2.0f) << "\n"; // false
    
    std::cout << Equal<double>(1.0 - 0.9999999999, 0.0000000001) << "\n"; // true
    std::cout << Equal<double>(1.0, 2.0) << "\n"; // false

    return 0;
}
