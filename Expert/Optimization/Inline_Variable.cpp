#include <iostream>

// #################################### Inline a Variable ####################################
// Notes:   Inline a variable make it possible to a static attribute to be use in a Class/Struct.
//          Constexpr are inline.

struct Structure{

    // A static variable can only be const
    static const int m_CONST_VAR {12};

    // To avoid that and usless code
    inline static int m_inline_var;
};


int main(){

    Structure s;
    s.m_inline_var = 10;
    std::cout << s.m_inline_var << "\n";

    return 0;
}