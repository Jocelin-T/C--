#include <iostream>

// #################################### Virtual functions (Dynamic Dispatch) ####################################
// Notes:   Dynamic dispatch allow to find, at run time, the correct function to call

class Base{
    public:
    Base(){ std::cout << "Base Constructor\n"; }
    virtual ~Base(){ std::cout << "Base Destructor\n"; } // with virtual, make a call after the derived destructor
    virtual void memberFnc() { std::cout << "Base Function\n"; }
};

class Derived : public Base{
    public:
    Derived(){ std::cout << "Derived Constructor\n"; }
    ~Derived(){ std::cout << "Derived Destructor\n"; }
    void memberFnc() override { std::cout << "Derived Function\n"; }
};

int main(){
    // In case "virtual" and "override"(only for functions) keyword are not used,
    //  the parent function and destructor are called,
    //  even with the instance of "Derived" created.
    Base* instance = new Derived;
    instance->memberFnc();
    instance->Base::memberFnc(); // Allow to use Base function
    delete instance;


    return 0;
}