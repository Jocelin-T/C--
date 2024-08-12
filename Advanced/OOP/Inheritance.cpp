#include <iostream>
// #################################### OOP Inheritance ####################################
    // inheritance =    A class can recieve attributes and methods from another class 
    //                  Children classes inherit from a Parent class
    //                  Helps to reuse similar code found within multiple classes
class Animal{ // Parent class
    public:
    // Attributes
        bool alive = true;

    // Methods
    void eat(){
        std::cout << "This animal is eating\n";
    }
};
class Dog : public Animal{ // Children class
    public:

    void drink(){
        std::cout << "This animal is drinking\n";
    }
};
class Cat : public Animal{ // Children class
    public:

    void sleep(){
        std::cout << "This animal is sleeping\n";
    }
};


int main(){

    Dog dog; // Dog child class
    std::cout << dog.alive << "\n"; // inherit from Animal class
    dog.eat(); // inherit from Animal class
    dog.drink(); // method only in Dog class

    Cat cat; // Cat child class
    std::cout << cat.alive << "\n"; // inherit from Animal class
    cat.eat(); // inherit from Animal class
    cat.sleep(); // method only in Cat class


    return 0;
}