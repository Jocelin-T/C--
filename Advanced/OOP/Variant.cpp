#include <iostream>
#include <variant> // (C++ 17)


// #################################### Variant (tagged union) ####################################
// Notes:   It's add type safety for unions.


union U{
    int i;
    short s;
};

int main(){

    std::variant<int, float> data;
    std::cout << "union: " << sizeof(U) << " bytes\n"; // 4 bytes
    data = 7;
    std::cout << get<int>(data) << "\n";
    // std::cout << get<float>(data) << "\n"; // Compiler Error

    // it's possible to find the data type too
    data = 7.14f;
    if(auto attempt = std::get_if<float>(&data)){
        std::cout << "float find\n"; // data
    }

    return 0;
}