#include <iostream>
#include <string>

// #################################### std::string ####################################
// Notes:   std::string         => std::basic_string<char>
//          std::string_literal => const char*
//          NULL terminator     => "\0" (it's a zero), end a string


int main(){

    std::string s {"Ciao"};

    // Return the number of characters without the NULL terminator 
    std::cout << s.size() << "\n";

    // Return the number of characters in the current allocated storage
    std::cout << s.capacity() << "\n";

    // Make a request to try to resize down the size of the storage of the String
    s.shrink_to_fit();
    std::cout << s.capacity() << "\n";

    // There is an operator overload "+=" to concatenate 2 Strings
    s += " Added String";
    std::cout << s << "\n";

    // Possible to access any char, because it's an array
    s[3] = 'O';

    // Return a pointer or the address of the String
    std::cout << &s << "\n"; // address
    std::cout << s.data() << "\n"; // pointer


    return 0;
}