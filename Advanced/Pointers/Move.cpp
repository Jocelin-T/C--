#include <iostream>
#include <string>

// #################################### std::move ####################################

int main() {
    
    // Construct a new string. This uses copy constructor
    // We have an "rvalue" on the right and that will be
    // copied into "myString" using the copy constructor.
    std::string myString = "copy construct me";
    std::string newValue;

    std::cout << "myString A: " << myString << "\n";
    std::cout << "newValue A: " << newValue << "\n";

    // std::move allows us to "steal" the value
    newValue = std::move(myString);

    std::cout << "myString B: " << myString << "\n";
    std::cout << "newValue B: " << newValue << "\n";

    // Could more explicitly call the static cast here to move
    // the value of myString into newValue, like this:
    // newValue = static_cast<std::string&&>(myString);

    // Note:    myString still exist.
    //          if the myString was const, then it will copy the value.
    return 0;
}