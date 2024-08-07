#include <iostream>

// #################################### Dynamic Memory ####################################
int main(){
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ 
    // /!\  When using pointers, be careful that your code isn't   /!\ 
    // /!\  dereferencing "nullptr" or pointing to free memory     /!\ 
    // /!\  this will cause undefined behavior !!!                 /!\ 
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ 

    // dynamic memory = Memory that is allocated after the program
    //                  is already compiled and running.
    //                  Use the "new" operator to allocate
    //                  memory in the heap rather than the stack

    //                  Useful when we don't know how much memory
    //                  we will need. Makes our programs more flexible,
    //                  especially when accepting user input.

// ****************************** Dynamic Variables ******************************
    int *pNum = NULL; // declare NULL to a pointer
    pNum = new int; // allocate memory to the heap
    // int *pNum = new int; // can be done like that
    *pNum = 25; // set the value at this address

    std::cout << "Address: " << pNum << "\n";
    std::cout << "Value: " << *pNum << "\n";

    delete pNum;    // free the memory at this address, 
                    // !!! NEED TO BE DONE or can cause memory leak !!!

// ****************************** Dynamic Arrays ******************************
    int size;
    std::cout << "How many grade to enter in: ";
    std::cin >> size;

    char *pGrades = NULL; // do not declare as an array
    // int *pNum = new int[size]; // can be done like that:
    pGrades = new char[size]; // allocate memory to the heap

    for(int i = 0; i < size; i++){
        std::cout << "Enter grade " << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    for(int i = 0; i < size; i++){
        std::cout << "Grade [" << i + 1 << "]\nAdress: " << static_cast<void*>(&pGrades[i]) << " Value: " << *(pGrades + i) << "\n";
                                                        // can be write this way because it's an array: << pGrades[i] << "\n";
                                                        // static_cast<void*>(&pVariable[i]) will stop the "cout" when value is void
                                                        // because the dynamic memory create void value, 
                                                        // it's only for visual in this code !!
    }

    delete[] pGrades;   // free the memory at this address, 
                        // !!! NEED TO BE DONE or can cause memory leak !!!

    return 0;
}