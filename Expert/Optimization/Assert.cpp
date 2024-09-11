#include <cassert> // for assert
#include <iostream>

// #################################### Assert and static_assert ####################################
// Notes:   Assert test the parameters and return a boolean.
//          Optionally, can return a message after.
//          "Assert" is done at runtime.
//          "Static_assert" is done at compile time and it's Modern C++.

void CheckAge(int check_age){
    assert(check_age > 0 && "assert: age is less than 0");
}

int main(){

    int age_1 = -7;
    CheckAge(age_1); // will fail at runtime
    
    // when using static_assert, 
    //  variables or functions NEED to be constexpr
    constexpr int age_2 = -7;
    static_assert(age_2 > 0, "static_assert: age is less than 0"); // will fail at compile time

    constexpr int age_3 = 7;
    static_assert(age_3 > 0, "static_assert: age is less than 0"); // is correct
    return 0;
}