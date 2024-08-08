#include <iostream>

// #################################### Variadic Functions and Variadic Arguments ####################################
// Notes:   Variadic is the possibility to change the number of parameters of a function.
//          The use of parameter pack: template<typename AnyName, typename... AnyName> make it possible

template<typename T> 
T Sum(T x){
    return x;
}

template<typename T, typename... Args> 
T Sum(T start, Args... others){
    return start + Sum(others...);
}

int main(){

    // Sum() function NEED to have 2 templates parameters to be enough precis
    //  of what data type is treated here.
    std::cout << Sum<double, double>(1, 2.4528f, 3.7155842682, 4, 5) << "\n";
    std::cout << Sum<float, float>(1, 2.45f, 3.71f, 4, 5) << "\n";
    std::cout << Sum<float, double>(1, 2.45f, 3.7155842682, 4, 5) << "\n";

    return 0;
}
