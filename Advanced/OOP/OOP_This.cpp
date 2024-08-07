#include <iostream>


// #################################### Keyword: This ####################################
// Notes:   


class Person{
    public:
    Person(int age) {
        this->m_age = age;
    }

    int GetAge(){
        return m_age;
    }

    private:
    int m_age;
};

int main(){

    Person j{25};
    std::cout << j.GetAge() << "\n";

    return 0;
}