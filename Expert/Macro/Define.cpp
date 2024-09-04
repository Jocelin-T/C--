#include <iostream>

// #################################### Pre_Processing ####################################
// Notes:   The character "#" is a textual replacement.
//          Textual replacement is done before the compilation of the code 
//           (-E has args when using CMD line to see the textual replacement).
//          For changing a define when launching with the CMD line use -DNAME=the_value, like this:
//           for changind DEBUG -> -DDEBUG=0
//          #ifndef => if not define
//          #ifdef  => if define


// Define attribut a value to a symbol, here PI is the symbol.
#define PI 3.1415926


// Now it's better to use constexpr for type safety
// constexpr float PI { 3.1415926 };


// Here a header guard:
// At the top of the file:
#ifndef MAIN_HPP
#define MAIN_HPP
    // Here the all the code

#endif // REQUIRED, after a ifdef/ifndef 
// Now it's replaced by #pragma once


// Here another way to use ifdef/ifndef
#ifndef DEBUG // if DEBUG is not define then:
#define PI2 3.14
#endif // REQUIRED, after a ifdef/ifndef 

#define DEBUG 1// define the "variable" DEBUG as a logical 1 (true)

int main(){


    #if DEBUG // if DEBUG is true (1)
        std::cout << PI2 << "\n";
    #else
        std::cout << "Not debug\n";
    #endif  // REQUIRED, after a #if


    return 0;
}