#include <iostream>
#include <string>


// #################################### Delegating Constructor ####################################
// Notes:   To avoiding repeating code, like here multiple constructors can be create for multiple
//          cases. 
//          Delegating is a way to call a constructor in a other constructor.
//          In case of using delegation constructor, it's NOT possible to initialize members variables,
//           (Entity(std::string name) : m_name(name), Entity() {}) => Will be an Error!

// Base Class
struct Entity{
    // Base constructor, will call the init() function
    Entity() {
        init();
    }
    // Delegating Constructor, will initialize the Base constructor,
    //  then apply the modification.
    Entity(std::string name) : Entity() {
        m_name = name;
    }

    // Members
    std::string m_name;
    int m_x{0}, m_y{0};

    private:
    // Initialization
    void init(){
        m_x = 7;
        m_y = 3;
        m_name = std::to_string(m_x) + std::to_string(m_y);
    }
};

int main(){

    Entity j{"jo"};
    std::cout << j.m_name << "\n";
    std::cout << j.m_x << "\n";
    std::cout << j.m_y << "\n";


    return 0;
}