#include <iostream>


// #################################### Static Casting ####################################
// Notes:   Converts between types using a combination of implicit and user-defined conversions.
//          Less expensive, more dangerous than dynamic_cast.
//          Possible to use pointers, but NOT safe.

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

    // Simple to understand, even if C-Style cast will work.
    float f {3.14f};
    int i = static_cast<int>(f);
    std::cout << i << "\n";

    // With Class/Struct
    Base b;
    Derived d;
    b.Do();
    d.Do();

    // Treat "Derived" Object as a "Base" Object.
    static_cast<Base>(d).Do();

    // Won't work to treat "Base" Object as a "Derived" Object.
    // static_cast<Derived>(b).Do();

    // Function NEED to be virtual if they are not polymorphic
    Base* p_b = new Base;
    Base* p_d = new Derived;

    static_cast<Derived*>(p_b)->Do(); // need virtual static NOT safe
    p_d->Do();

    return 0;
}