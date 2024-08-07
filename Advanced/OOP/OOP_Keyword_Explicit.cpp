#include <iostream>


// #################################### Keyword: explicit ####################################
// Notes:   Good pratice to stop the compiler to trunk data.

class UDT{
    public:
    // Explicit Constructor
    explicit UDT(int i){
        m_variable = i;

        std::cout << "m_variable: " << m_variable << "\n";
    }

    private:
    int m_variable;
};

int main(){

    // // Objects creation
    // UDT ul{500.1f}; // compilation error, but GOOD
    // UDT ui(500.1f); // don't stop trunk, can cause errors
    // UDT uo = 500.1f; // error, won't work

    return 0;
}