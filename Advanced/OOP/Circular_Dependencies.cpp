#include <iostream>

// #################################### Circular Dependencies ####################################
// Notes:   It's when 2 Class/Struct have an Object of the other one, forming a "circle".
//          Here some design to manage this problem:
//              - Use a pointer for one of the Object and a forward declaration
//              - Different Headers for heach Class/Struct
//              - A new Class/Struct holding the 2 others
//              - Redesign


// ==== Pointer ==== //
class B; // Forward declaration

class A {
    B* b; // A uses B
};

class B {
    A* a; // B uses A
};


int main(){



    return 0;
}