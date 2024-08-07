#include <iostream>

// #################################### Pointers ####################################
int main(){
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\/
    // /!\  When using pointers, be careful that your code isn't   /!\/
    // /!\  dereferencing "nullptr" or pointing to free memory     /!\/
    // /!\  this will cause undefined behavior !!!                 /!\/
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\/

    // pointers =   variable that stores a memory address of another variable
    //              sometimes it's easier to work with an address
    //  &   address of operator
    //  *   dereference operator
    
// ****************************** Variables ******************************
    std::string name = "Jocelin";
    std::string *pName = &name; // convention for pointers is '*pVariable'

    std::cout << "Variables\n";
    std::cout << "Memory address: " << pName << "\n";
    std::cout << "Value address: " << *pName << "\n";

// ****************************** Arrays ******************************
    std::string freePizzas[5] = {"pizza_1", "pizza_2", "pizza_3", "pizza_4", "pizza_5"};
    std::string *pFreePizzas = freePizzas; // an array is already a pointer so dont need "&"

    std::cout << "Array:\n";
    std::cout << "Array address: " << freePizzas << "\n"; // Same as memory address
    std::cout << "Memory address: " << pFreePizzas << "\n"; // Same as array address
    std::cout << "Value address: " << *pFreePizzas << "\n"; // will be the same as "freePizzas[0]"
    std::cout << "Value address: " << *(pFreePizzas+1) << "\n"; // will be the same as "freePizzas[1]"

    return 0;
}