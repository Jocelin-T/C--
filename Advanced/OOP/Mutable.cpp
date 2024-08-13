#include <iostream>

// #################################### Mutable ####################################
// Notes:   Mutable allow to change a const variable.
//          It's principaly used 

struct Point3f{
    explicit Point3f(float _x, float _y, float _z)
    : m_x(_x), m_y(_y), m_z(_z), m_w(1.0f)
    {}

    void ChangeW(float new_w) const{
        m_w = new_w; // change is allowed 
    }

    float m_x, m_y, m_z; 
    mutable float m_w; // is mutable
};

int main(){

    Point3f p{1.0f, 2.0f, 3.0f};
    p.ChangeW(5.0f);

    std::cout << p.m_x << "\n" 
            << p.m_y << "\n" 
            << p.m_z << "\n" 
            << p.m_w << "\n";

    return 0;
}