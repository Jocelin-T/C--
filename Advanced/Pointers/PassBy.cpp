#include <iostream>

// #################################### Pass by VALUES or REFERENCES ####################################
void swapByValues(std::string x, std::string y);
void swapByReferences(std::string &x, std::string &y);
int main(){
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
    // /!\  When using pointers, be careful that your code isn't   /!\
    // /!\  dereferencing "nullptr" or pointing to free memory     /!\
    // /!\  this will cause undefined behavior !!!                 /!\
    // /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\ /!\
    
    std::string x = "Tea";
    std::string y = "Coffee";
    std::string temp;

    std::cout << "Starting Variables" << "\n"; 
    std::cout << "X = " << x << "\n"; 
    std::cout << "Y = " << y << "\n"; 

    // without functions
    temp = x;
    x = y;
    y = temp;
    std::cout << "Without functions" << "\n"; 
    std::cout << "X = " << x << "\n"; 
    std::cout << "Y = " << y << "\n"; 

    swapByValues(x, y);
    std::cout << "After function swapByValues()" << "\n"; 
    std::cout << "X = " << x << "\n"; 
    std::cout << "Y = " << y << "\n"; 

    swapByReferences(x, y);
    std::cout << "After function swapByReferences()" << "\n"; 
    std::cout << "X = " << x << "\n"; 
    std::cout << "Y = " << y << "\n"; 

    return 0;
}
// ****************************** Pass by VALUES ******************************
// Passing classic parameters in function while be pass by VALUES
// The function get a copy of the original values
// NO CHANGE will occure
void swapByValues(std::string x, std::string y){
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

// ****************************** Pass by REFERENCES ******************************
// Passing parameters with "&" operator while be pass by REFERENCES
// The function get the memory address (the original values)
// A CHANGE will occure
void swapByReferences(std::string &x, std::string &y){ // the "&" operator just need to be inside the parameters
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}