#include <iostream>
// #################################### OOP Constructor ####################################
class Student{
    public:
        // Attributes
        std::string name;
        int age;
        double gpa;

    // Constructor NEED the same name as the class
    // Constructor with is parameter (look like a function)
    Student(std::string name, int age, double gpa){
        // this->attribute = parameter
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
    // IF Attributes names and parameters name ARE NOT THE SAME:
    // Student(std::string x, int y, double z){
    //     // attribute = parameter
    //     name = x;
    //     age = y;
    //     gpa = z;
    // }
};

int main(){
    // constructor =    special method that is automaically called when an object is instantiated
    //                  useful for assigning values to attributes as arguments

    Student student_1("Jocelin", 27, 3.1); // add "()" after the object name

    std::cout << student_1.name << "\n";
    std::cout << student_1.age << "\n";
    std::cout << student_1.gpa << "\n\n";

    Student student_2("Adrien", 37, 3.5);

    std::cout << student_2.name << "\n";
    std::cout << student_2.age << "\n";
    std::cout << student_2.gpa << "\n";
    return 0;
}