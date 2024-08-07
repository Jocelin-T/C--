#include <iostream>

// #################################### Overloading a function ####################################
// functions can share the same name, ONLY IF there parameters are different
void myFunction(){
    std::cout << "this is a simple function without parameter\n";
}
void myFunction(std::string para_1){ // This is function overloading
    std::cout << "this is a simple function " << para_1 << " parameter\n";
}

int main(){

    myFunction("with 1");

    return 0;
}