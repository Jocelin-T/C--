#include <iostream>
#include <string>
#include <memory>

// #################################### Pointer to implementation (pIMPL) ####################################
// Notes:   This will completly hide (no code) the private part of a Class/Struct, who is inside a Header file.
//          The use of pIMPL as LESS performances, but worth the trade when needed! 


// ******************* Header file (Visible) *******************
class Person{
    public:
    Person(std::string s);
    ~Person();
    std::string GetAttributes();

    private: // No value visible in this part
    struct pImplPerson;
    // pImplPerson* m_impl; // raw ptr
    std::unique_ptr<pImplPerson> m_impl; // Modern ptr
};

// ******************* Source file (Hidden) *******************
struct Person::pImplPerson{
    std::string m_name;
    std::string m_strength;
    std::string m_speed;
};

Person::Person(std::string s) {
    // m_impl = new pImplPerson; // raw ptr
    m_impl = std::make_unique<pImplPerson>(); // Modern ptr
    m_impl->m_name = s;
    m_impl->m_strength = "n/a";
    m_impl->m_speed = "n/a";
}

Person::~Person(){
    // delete m_impl; // NEEDED if raw ptr
}

std::string Person::GetAttributes(){
    return m_impl->m_name + ", " +  m_impl->m_strength + ", " + m_impl->m_speed;
}


// ******************* Main file *******************
int main(){

    Person jo("Jo");
    std::cout << jo.GetAttributes() << "\n";

    return 0;
}