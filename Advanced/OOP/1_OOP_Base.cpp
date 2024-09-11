#include <iostream>
// #################################### OOP Basic ####################################
    // object = A collection of attributes (Variables) and methods (Functions)
    //          They can have characteristics and could perform actions
    //          Can be used to mimic real world items 
    //          Created from a class which acts as a Blue-Print

// ****************************** Class ******************************
struct Role{
    std::string name{""};
    int access{0};
};

class Human{
    public:
        // Attributes
        std::string name;
        std::string job = "student"; // a value can be set by default
        int age;

        // Methods
        void eat(){
            std::cout << "This person is eating\n";
        }
        void drink(){
            std::cout << "This person is drinking\n";
        }
        void sleep(){
            std::cout << "This person is sleeping\n";
        }
}; // Don't forget ";" HERE

int main(){
    Role role_emp;
    role_emp.access = 1;
    role_emp.name = "Clownz";
    // creation of an Object
    Human human_1;
    // set the attributes of the object
    human_1.name = "Jocelin";
    human_1.job = "Infra, Operator, Dev";
    human_1.age = 27;

    std::cout << human_1.name << "\n";
    std::cout << human_1.job << "\n";
    std::cout << human_1.age << "\n";

    // call the methods of the object
    human_1.eat();
    human_1.drink();
    human_1.sleep();

    return 0;
}