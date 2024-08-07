#include <iostream>


// #################################### Keyword: This ####################################
// Notes:   "This" keyword is a pointer to the current instance of the Object


class Person{
    public:
    Person(int age) {
        this->m_age = age;
    }

    int GetAge() const{
        return m_age;
    }

    // With "this"
    int GetThisAge() const{
        return this->m_age;
    }

    Person* GetThisAddress() {
        return this;
    }

    // // Possible but to avoid
    // ~Person(){
    //     delete this;
    // }

    private:
    int m_age;
};

int main(){
    // In the stack
    Person j{25};
    std::cout << j.GetThisAge() << "\n";
    std::cout << "[this] Address: " << j.GetThisAddress() << "\n";
    std::cout << "Object Address: " << &j << "\n";

    // In the heap
    Person* k = new Person(27);
    std::cout << k->GetThisAge() << "\n";
    std::cout << "[this] Address: " << k->GetThisAddress() << "\n";
    std::cout << "Pointer Address: " << &k << "\n"; // Return the address of the ptr
    std::cout << "Object Address: " << k << "\n"; // Return the address of the object
    delete k;

    return 0;
}