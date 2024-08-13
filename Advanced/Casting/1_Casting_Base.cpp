#include <iomanip>
#include <ios>
#include <iostream>
#include <utility>


// #################################### Casting (C-Style) ####################################
// Notes:   Casting is converting the data type of a variable.
//          Implicite casting is an automatic casting and is at runtime.
//          Avoid casting when possible, prefer dynamic_cast if needed,
//           if performance is needed, use static_cast.

int main(){

    std::cout << std::fixed;
    std::cout << std::setprecision(6); // decimal precision
    std::cout << 7/5 <<"\n"; // numbers are int type

    // 7 is cast as float and 5 is an implicit casting.
    std::cout << (float)7/5 <<"\n"; 

    int result = 50000;
    // This implicit casting will work but the result is incorrect,
    //  because of the number of bytes for the data types.
    short s = result; 
    unsigned short u_s = result; // this will be correct
    std::cout << s << "\n";
    std::cout << sizeof(result) << "\n";
    std::cout << sizeof(s) << "\n";

    // The comparison of variables, is a comparison of bytes.
    int i = -2;
    unsigned int u = 1;

    if(i>u){
        std::cout << "i greater than u\n"; 
    }
    // To make a comparison of different data type, use std::cmp_
    if(std::cmp_greater(i, u)){
        std::cout << "should not print\n"; 
    }

    // For readability it's possible to add suffix,
    //  very usefull when using auto.
    unsigned long u_l = 1000000ul;
    auto u_l_2 = 1000000ul;

    // Possible to add ' too, but it's just visible in the code. 
    unsigned long one_million = 1'000'000ul;
    std::cout << one_million << "\n";

    return 0;
}