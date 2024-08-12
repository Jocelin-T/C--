#include <iostream>

// #################################### Struct (Structure) ####################################
struct student{
    std::string name;
    double gpa;
    bool learn = true; // set of a default value
}; // don't forget ";"

struct Car{
    std::string model;
    int year;
    std::string color;
};
void printCarValue(Car car);
void printCarReference(Car &car);
void paintCar(Car &car, std::string color);
int main(){
    // struct = A structure that group related variables under one name.
    //          structs can contain many different data types (string, int, double, bool, ...)
    //          variables in a struct are known as members
    //          members can be access with "." (Class Member Access Operator)

    student student_1;
    student_1.name = "Jocelin";
    student_1.gpa = 3.2;
    // student_1.learn = true; // default set in declaration

    student student_2;
    student_2.name = "Jo";
    student_2.gpa = 3.5;
    student_2.learn = false; // override of the default value

    std::cout << student_1.name << "\n";
    std::cout << student_1.gpa << "\n";
    std::cout << student_1.learn << "\n"; // 1 is true

    std::cout << student_2.name << "\n";
    std::cout << student_2.gpa << "\n";
    std::cout << student_2.learn << "\n"; // 0 is false

    // ****************************** Pass struct as argument ******************************
    Car car_1;
    Car car_2;

    car_1.model = "Mustang";
    car_1.year = 2024;
    car_1.color = "Blue";

    car_2.model = "Porsch";
    car_2.year = 2022;
    car_2.color = "Black";

    std::cout << "Real address: " << &car_1 << "\n"; 
    paintCar(car_1, "Gray");
    printCarValue(car_1);
    printCarReference(car_1);

    return 0;
}
void printCarValue(Car car){ // It's a copy
    std::cout << "Address copy by Value: " << &car << "\n"; 
    std::cout << car.model << "\n";
    std::cout << car.year << "\n";
    std::cout << car.color << "\n";
}
void printCarReference(Car &car){ // It's the original
    std::cout << "Address copy by Reference: " << &car << "\n"; 
    std::cout << car.model << "\n";
    std::cout << car.year << "\n";
    std::cout << car.color << "\n";
}
void paintCar(Car &car, std::string color){
    car.color = color;
}