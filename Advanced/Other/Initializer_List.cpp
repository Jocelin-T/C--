#include <iostream>
#include <initializer_list>
#include <vector>

// #################################### Initializer List ####################################
// Notes:   Difference between () and {} 


struct UDT{
    UDT(std::initializer_list<int>data){
        std::cout << "initializer_list Constructor\n";
        m_data = data;
    }

    UDT(int a, int b, int c){
        std::cout << "param Constructor\n";
    }

    void PrintData(){
            for(auto& i : m_data){
            std::cout << i << "\n";
        }
    }

    private:
    std::initializer_list<int> m_data;
};

int main(){

    // // **** () {} **** //
    // int a = 4.3; // Will be trunk to 4
    // int b(4.3); // Will be trunk to 4
    // int c{4.3}; // Compile Error: NEED to be the correct type

    // With "()" there is existing parameters who build 10 value of 1
    std::vector<int> v_1(10, 1);
    for(auto& i : v_1){
        std::cout << i << "\n";
    }

    // With "{}" this is a direct initialization
    std::vector<int> v_2{10, 1};
    for(auto& i : v_2){
        std::cout << i << "\n";
    }

    // When using "{}" the constructor with initialize_list as parameter will be call
    //  and the correct type is NEEDED
    UDT u_1{1,2,3};
    u_1.PrintData();

    // When using "()" the constructor with 3 int as parameter will be call
    UDT u_2(1, 2, 3);

    return 0;
}