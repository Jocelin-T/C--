#include <iostream>
#include <memory>

// #################################### Unique Pointers ####################################
// Notes:   Allocated on the Heap when using "std::make_unique"
//          Cannot be share (no copies), but can be move
//          Deleted at the end of the block scope {}


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
    // **** Pointer **** //
    // Unique pointer
    std::unique_ptr<UDT> p_object = std::unique_ptr<UDT>(new UDT);

    // Modern C++ of Unique pointer (Factory Pattern), don't need "new" keyword
    std::unique_ptr<UDT> p_modern_object = std::make_unique<UDT>();

    // Unique pointer of an Array
    std::unique_ptr<UDT[]> p_array = std::unique_ptr<UDT[]>(new UDT[10]);

    // Modern C++ of Unique pointer of an Array (Factory Pattern), don't need "new" keyword
    std::unique_ptr<UDT[]> p_modern_array = std::make_unique<UDT[]>(10);

    // **** Transfer Pointer **** //
    // std::move can be used for transferring ownership
    std::unique_ptr<UDT> p_object_moved = std::move(p_object);


    return 0;
}