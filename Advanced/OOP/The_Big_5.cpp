#include <iostream>
#include <string>
#include <vector>


// #################################### The Big 5 ####################################
// Notes:   When creating a Class there is a convention about constructor and destructor
//          who need to be created

class IntArray{
    public:
    // (1) Constructor
    IntArray(std::string name) : m_name(name), m_data(new int[10]){
        std::cout << m_name << " was constructed\n";
    }
    // (2) Destructor
    ~IntArray(){
        std::cout << m_name << " was destroyed\n";
        delete [] m_data;
    }
    // ****** Copy of an object ****** //
    // (3) Copy Constructor policy
    IntArray(const IntArray& rhs){
        m_name = rhs.m_name + " (copy)";
        std::cout << m_name << " was copy constructed form: " << rhs.m_name << "\n";
        m_data = new int[10];
        for(int i = 0; i < 10; i++){
            m_data[i] = rhs.m_data[i];
        }
    }
    // Copy assignment operator policy
    IntArray& operator=(const IntArray& rhs){
        if(this != &rhs){
            delete [] m_data;
            m_name = rhs.m_name + " (copy)";
            std::cout << m_name << " was copy assigned from: " << rhs.m_name << "\n";
            m_data = new int[10];
            for (int i = 0; i < 10; i++) {
                m_data[i] = rhs.m_data[i];
            }
        }
        return *this;
    }
    // ****** Transfer ownership of data from an object (move) ****** //
    // (4) Move Constructor policy
    IntArray(IntArray&& source){
        m_name = source.m_name;
        source.m_name = "";
        m_data = source.m_data;
        source.m_data = nullptr;
        std::cout << m_name << " was move constructed\n";
    }
    // (5) Move assignment operator policy
    IntArray& operator=(IntArray&& source){
        if(this != &source){
            m_name = source.m_name;
            source.m_name = "";
            m_data = source.m_data;
            source.m_data = nullptr;
            std::cout << m_name << " was move assignment\n";
        }
        return *this;
    }

    private:
    std::string m_name;
    int* m_data;
};


int main(){

    // Copy 
    IntArray array_1("array_1");
    IntArray array_2 = array_1;

    // Move
    std::vector<IntArray> my_arrays;
    for(int i = 0; i < 10; i++){
        IntArray temp(std::to_string(i));
        my_arrays.push_back(std::move(temp));
    }

    return 0;
}