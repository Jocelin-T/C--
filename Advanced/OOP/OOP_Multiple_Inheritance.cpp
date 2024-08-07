#include <iostream>


// #################################### Multiple Inheritance ####################################
// Notes:   Here how to make it work when there is multiple inheritance.
//          Add virtual to the Base Class in the Derived Class.

// Base Class
struct Entity{
    int x{4}, y{5};
};
// Derived Class, add virtual before the base class
struct Goblin : virtual public Entity{
    int power{7};
};
// Derived Class, add virtual before the base class
struct Warrior : virtual public Entity{
    int power{10};
};
// Multiple Inheritance Class
struct Player : public Goblin, public Warrior{

};

int main(){

    Player jo;
    std::cout << jo.x << "\n";
    std::cout << jo.y << "\n";
    // Possible to select the derived class member like that:
    std::cout << jo.Goblin::power << "\n"; 


    return 0;
}