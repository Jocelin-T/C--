#include <iostream>

// #################################### Inline a function ####################################
// Notes:   Inline a function will try make the complier use other way to NOT call the function.
//          When calling a function there is an argument, a body(the code), a return and a return address.
//          Sometime only the body(the code) is needed, so to avoid useless movement, use "inline".
//          A function NEED to be simple (like here add()) to make inline work.
//          (+) The hardware can guess the nest instruction easily.
//          (+) Other optimization enabled, like here "4 + 5 = 9".
//          (-) More code to write.
//          (-) More difficult to debug

// The "__attribute__((always_inline))" will force the compiler to use inline, not required
__attribute__((always_inline)) inline int add(int a, int b){
    return a + b;
}

int main(){

    std::cout << add(4, 5) << "\n";

    return 0;
}