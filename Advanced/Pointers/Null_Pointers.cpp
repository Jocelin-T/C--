#include <iostream>

// #################################### NULL Pointers ####################################
int main(){
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ 
    // /!\  When using pointers, be careful that your code isn't   /!\ 
    // /!\  dereferencing "nullptr" or pointing to free memory     /!\ 
    // /!\  this will cause undefined behavior !!!                 /!\ 
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ 

    // Null pointers =  When a pointer is holding a null value,
    //                  that pointer is not pointing at anything
    // nullptr  = keyword represents a null pointer literal
    // nullptrs are helpful when determining if an address
    // was successfully assigned to a pointer

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;

    // Check if a pointer has an address
    if(pointer == nullptr){
        std::cout << "Pointer has no address\n";
    }
    else{
        std::cout << "Address (" << pointer << ") was assigned: " << *pointer << "\n";
        // Safe to put code here
    }

    return 0;
}