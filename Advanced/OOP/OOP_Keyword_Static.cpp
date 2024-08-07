#include <iostream>


// #################################### Keyword: static ####################################
// Notes:   Static variables are allocated in the binary (executable).
//          Static variables exist forever.
//          Class/Struct share the same static member.
//

// **** In free function **** //
void foo(){
    static int s_variable{0};
    s_variable += 1;
    std::cout << s_variable << "\n";
}

// **** In Class/Struct **** //
struct API{
    API(){}
    ~API(){}

    // Static members
    static int m_major; // NEED to be define outside the Class
    const static int M_MINOR{8};

    // Static members function (can't return as const)
    // NEED the "static" keyword when returning a static variable,
    //  NOT if declaration and variable are in the .header
    static int GetMajorVersion() {
        return m_major;
    }

};

int API::m_major = 7; // static definition

int main(){
    
    for(int i = 0; i < 10; i++) {
        foo(); // Here s_variable will increment
    }

    // API object;
    // object.m_major = 7; // Linker Error: 
    std::cout << "Major: " << API::m_major << "\n";
    std::cout << "Major: " << API::GetMajorVersion() << "\n";
    std::cout << "Minor: " << API::M_MINOR << "\n";

    return 0;
}