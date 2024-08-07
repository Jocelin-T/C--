#include <iostream>
// #################################### OOP Overloaded Constructor ####################################
class Pizza{
    public:
        std::string topping_1;
        std::string topping_2;

    // no contructor
    Pizza(){

    }
    // basic contructor 
    Pizza(std::string topping_1){
        this->topping_1 = topping_1;
    }
    // overloaded contructor 
    Pizza(std::string topping_1, std::string topping_2){
        this->topping_1 = topping_1;
        this->topping_2 = topping_2;
    }
};

int main(){
    // overloaded constructors =    multiple constructors with the same name but different parameters
    //                              allows for varying arguments when instantiating an object

    Pizza pizza_3; // IF there is no parameter don't put "()"

    Pizza pizza_1("ham");
    std::cout << pizza_1.topping_1 << "\n\n";

    Pizza pizza_2("mushrooms", "ham");
    std::cout << pizza_2.topping_1 << "\n";
    std::cout << pizza_2.topping_2 << "\n\n";

    return 0;
}