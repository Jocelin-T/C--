#include <iostream>
#include <memory>

// #################################### Shared Pointers ####################################
// Notes:   Allocated on the Heap when using "std::make_shared"
//          Own the reference, how many pointer are pointing on the ressource
//          Deleted at the end of the block scope {}
//          When reference count is egal to 0, then the ressource is destroyed

class UDT{
    public:
    UDT() {
        std::cout << "UDT Created\n"; 
    }    
    ~UDT() {
        std::cout << "UDT Destroyed\n"; 
    }
};

int main() {

    // Shared Pointer
    std::shared_ptr<UDT> p_ptr1 = std::make_shared<UDT>();

    // Reference count in a scope
    {
        std::shared_ptr<UDT> p_ptr2 = p_ptr1;
        std::cout << "Reference count: " << p_ptr1.use_count()  << "\n";
    }
    // Reference count after a scope
    std::cout << "Reference count: " << p_ptr1.use_count() << "\n";

    return 0;
}