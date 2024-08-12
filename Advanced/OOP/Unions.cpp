#include <iostream>


// #################################### Unions ####################################
// Notes:   Unions is almost the same as a Struct, but:
//          Compare to Struct who addition all data type together,
//           unions hold the largest type only.
//          Can't have virtual function, be a base Class or have a base Class


union U{
    int i;
    short s;
};

int main(){

    U my_union;
    my_union.i = 50;

    std::cout << "int: " << my_union.i << "\n"; // will be 50
    std::cout << "short: " << my_union.s << "\n"; // will be 50 too

    std::cout << "int: " << sizeof(int) << " bytes\n"; // 4 bytes
    std::cout << "short: " << sizeof(short) << " bytes\n"; // 2 bytes
    std::cout << "union: " << sizeof(my_union) << " bytes\n"; // 4 bytes

    return 0;
}