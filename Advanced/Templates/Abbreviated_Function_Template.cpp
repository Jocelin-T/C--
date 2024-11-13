#include <iostream>

// #################################### Abbreviated Functions Template (Keyword: auto) ####################################
// Notes:   Auto keyword will do the same for basic type as a simple type for math, like int, double, float.
//          Abbreviated function template NEED C++ 20 or more.


// // auto will do the same job here
// template <typename T> 
// T Square(T x){
//     return x * x;
// }

auto GetSquare(auto x){
    return x * x;
}

int main(){

    std::cout << "int: " << GetSquare(5) << "\n";
    std::cout << "double: " << GetSquare(5.5) << "\n";
    std::cout << "float: " << GetSquare(6.5f) << "\n";

    return 0;
}
