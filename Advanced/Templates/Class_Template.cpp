#include <iostream>

// #################################### Classes Template ####################################
// Notes:   Template arguments is REQUIRE when creating a Object (can be avoid with CTAD).
//          Possible to set default value to Template: template<typename T = double, int Size = 5>

// Custom array Class
// T => data type
// Size => size of the array
template<typename T, int Size>
class Container{
    public:
    Container(){
        m_data = new T[Size];
        std::cout << "Contructor Call\n"; 
    }
    ~Container(){
        std::cout << "Destructor Call\n"; 
        delete [] m_data;
    }

    static T m_variable;

    private:
    T* m_data;
};

// When creating static variable, NEED a declaration outside the Class/Struct
template<typename T, int Size>
T Container<T, Size>::m_variable;

int main(){

    Container<int, 10> i;
    Container<float, 10> f;
    Container<double, 10> d;

    Container<int, 5>::m_variable = 7; // NEED a declaration before
    std::cout << Container<int, 5>::m_variable << "\n";

    Container<int, 5>::m_variable = 8; 
    std::cout << Container<int, 5>::m_variable << "\n";

    return 0;
}
