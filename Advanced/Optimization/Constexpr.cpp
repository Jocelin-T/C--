#include <iostream>

// #################################### Constant Expression (constexpr) ####################################
// Notes:   Contrexpr is calculation of a constant at compile time.
//          The keyword "constexpr" NEED to be before the functions AND the variables.


constexpr int add(int a, int b){
    return a + b;
}

int main(){

    constexpr int i = add(7, 16);
    std::cout << i << "\n";

    // it's possible that runtime and compile time
    //  don't give the same result.
    constexpr float cf = 3.1411626f * 3.0f;
    float f = 3.1411626f * 3.0f;
    std::cout << cf << "\n";
    std::cout << f << "\n";

    return 0;
}