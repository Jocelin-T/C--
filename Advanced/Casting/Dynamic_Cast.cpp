#include <iostream>


// #################################### Dynamic Casting ####################################
// Notes:   Safely converts pointers and references to classes up, down, 
//           and sideways along the inheritance.
//          Need to be a pointer/reference type.
//          Need to have virtual function when using pointers.

struct Base{
    int base_data{1};

    Base() {
        base_data = 11;
    }

    virtual void Do(){
        std::cout << "Base::Do()\t" << base_data << "\n";
    }

};

struct Derived : Base{
    int derived_data{2};

    Derived() {
        derived_data = 22;
    }

    void Do() override{
        std::cout << "Derived::Do()\t" << derived_data << "\n";
    }
};

int main(){

    // Function NEED to be virtual if they are not polymorphic
    Base* p_b = new Base;
    Base* p_d = new Derived;

    // Not valid
    if(dynamic_cast<Derived*>(p_b)){
        std::cout << "Treating (p_b) like Derived\n";
    }

    // Valid (d) inherit of Base.
    if(dynamic_cast<Base*>(p_d)){
        std::cout << "Treating (p_d) like Base\n";
        // Regular function call
        p_d->Do();
        // Can call explicitly different member functions in hierarchy
        p_d->Base::Do();
        p_d->Do();

        // For lower performances cost, now it's safe 
        //  to use "static_cast".
        (static_cast<Base*>(p_d))->Base::Do();
        (static_cast<Base*>(p_d))->Do();
    }

    // 
    

    return 0;
}