#include <iostream>

// #################################### Lambdas in OOP ####################################
// Notes:   For capturing a member variable by reference in the current
//           instance, just capture "this".
//          And for capturing by copy, capture "*this"

struct MyStruct{

    void Function(){     
        // Capture "this" by reference   
        auto f = [this] () {
            counter++;
            std::cout << "Counter in lambda: " << counter << "\n";
        };

        // Capture "this" by copy 
        auto ff = [*this] () {
            std::cout << "Counter in lambda: " << counter << "\n";
        };

        f();
        std::cout << "Counter: " << counter << "\n";
    }

    int counter{0};
};

int main(){

    MyStruct instance;
    instance.Function();
    instance.Function();
    instance.Function();
    instance.Function();

    return 0;
}