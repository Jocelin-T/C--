#include <iostream>


// #################################### Composition and Aggregation ####################################
// Notes:   Inheritance = "is a"    => Character is a Point2D.
//          Composition = "has a"   => Character has a Point2D. (like any member)
//          Aggregation = "has a"   => Lifetime is not necessarily tied to the object 


struct Point2D{
    int x, y;
};

class Character{
    public:
    Character(Point2D& home) : ref_home(home){

    }
    ~Character(){}

    private:
    Point2D m_position; // composition
    Point2D m_direction; // composition
    Point2D& ref_home; // aggregation
};

int main(){

    Point2D a_point; // object not tied to character
    Character jo(a_point);

    return 0;
}