#include <iostream>
#include <string>

// #################################### std::string_view ####################################
// Notes:   String_view avoid an allocation, to use only when there is no modification


void printString(const std::string_view& param){
    std::cout << param << '\n';
}

int main(){

    std::string s{"This is a really long string ..."};
    const char* c{"This is a really long char array ..."};


    printString(s);
    printString(c);

    std::string str{"Ciao"};
    std::string_view sview{str};

    std::cout << "     string: " << sizeof(str) << '\n';    // 32 bytes
    std::cout << "string_view: " << sizeof(sview) << '\n';  // 16 bytes

    return 0;
}