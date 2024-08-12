#include <iostream>
#include <memory>

// #################################### Deleter ####################################
// Notes:   Work only with unique_ptr.
//          With Deleter it's possible to delete a object in a specific order, 
//           should be used with File.


struct IntDeleter{
    void operator()(int* int_ptr){
        std::cout << "IntDeleter called\n"; 
        delete int_ptr;
    }
};

int main() {
    // make_unique<Type>() don't work
    // std::unique_ptr<IntDeleter> my_ptr = std::make_unique<IntDeleter>();

    std::unique_ptr<int, IntDeleter> my_ptr(new int);

    return 0;
}