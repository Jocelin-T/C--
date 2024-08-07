#include <iostream>

// #################################### Memory Address ####################################
int main(){
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
    // /!\  When using pointers, be careful that your code isn't   /!\
    // /!\  dereferencing "nullptr" or pointing to free memory     /!\
    // /!\  this will cause undefined behavior !!!                 /!\
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\

    std::string name = "Joce";
    int age = 27;
    bool student = true;
    // The operator "&" (addess of operator)
    std::cout << "Memory address of name: " << &name << "\n";
    std::cout << "Memory address of age: " << &age << "\n";
    std::cout << "Memory address of student: " << &student << "\n";

    return 0;
}