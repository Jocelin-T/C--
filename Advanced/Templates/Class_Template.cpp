#include <iostream>

// #################################### Classes Template ####################################
// Notes:   Template arguments is REQUIRE when creating a Object.

// Custom array Class
// T => data type
// Size => size of the array
template<typename T, int Size>
class Container{
    public:
    Container(){
        std::cout << "Contructor Call\n"; 
        m_data = new T[Size];
    }
    ~Container(){
        std::cout << "Destructor Call\n"; 
        delete [] m_data;
    }

    private:
    T* m_data;
};

int main(){

    Container<int, 10> i;
    Container<float, 10> f;
    Container<double, 10> d;

    return 0;
}
