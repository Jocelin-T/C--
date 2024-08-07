#include <iostream>
#include <memory>

// #################################### Weak Pointers ####################################
// Notes:   Allocated on the Heap when using "std::make_weak"
//          Non-owning pointer, doesn't increase the reference count
//          Deleted at the end of the block scope {}
//          To use with shared_ptr, safer way to have dangling pointers and break cycles
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
    // **** Weak Pointer **** //
    // Weak pointer declaration
    std::weak_ptr<UDT> p_ptr2;
    {
        // Shared Pointer
        std::shared_ptr<UDT> p_ptr1 = std::make_shared<UDT>();
        {
            // Reference count in a scope holding a weak_ptr is not updated
            p_ptr2 = p_ptr1;
            std::cout << "Reference count in scope: " << p_ptr2.use_count()  << "\n";
        }
        // Reference count after a scope
        std::cout << "Reference count: " << p_ptr1.use_count() << "\n";
    }
    // **** expired **** //
    std::cout << "Is weak_ptr expired (object is destroyed? ): " << p_ptr2.expired() << "\n";

    std::cout << "Destructor is call before whis line\n";

    return 0;
}