#include <iostream>

// #################################### Template (Generics) ####################################
// Notes:   Serve as a blueprint for the compiler to generate code for us.
//          Avoid copy and paste.
//          Don't work if function is after "main()", even with function declaration!

// Template creation, only 1 data type is accepted here
template <typename T> 
T square(T x){
    return x * x;
}

int main(){

    std::cout << "int: " << square(5) << "\n";
    std::cout << "double: " << square(5.5) << "\n";
    std::cout << "float: " << square(6.5f) << "\n";

    return 0;
}
