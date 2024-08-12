#include <iostream>
#include <ostream>

// #################################### OOP Overloading Operator ####################################
// Notes:   It's possible to overload an operator, so don't need to create a function for that.

class Vector3f{
    public:

    // Constructor
    Vector3f(){
        x = 0.0f;
        y = 1.0f;
        z = 2.0f;
    }

    // Members
    float x, y, z;

    // **** Overloading the operator [+] **** //
    // rhs => Right Hand Sight
    Vector3f operator+(const Vector3f& rhs) const {

        Vector3f result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;

        return result;
    }

    // **** Overloading the operator [++] as prefix (++my_object) **** //
    Vector3f operator++() {

        x = x + 1;
        y = y + 1;
        z = z + 1;

        return *this;
    }

    // // **** Overloading the operator [==] INSIDE a Class **** //
    // // If there is a overloading of the same operator, 
    // //  the one INSIDE the Class will be used.
    // // rhs => Right Hand Sight
    // bool operator==(const Vector3f& rhs) const {
    //     if (
    //         x == rhs.x
    //         && z == rhs.z
    //         && y == rhs.y
    //         ){
    //         return true;
    //     }
    //     return false;
    // }
};

// **** Overloading the operator [==] OUTSIDE a Class (free function)  **** //
// If there is a overloading of the same operator, 
//  the one INSIDE the Class will be used.
// lhs => Left Hand Sight
// rhs => Right Hand Sight
bool operator==(const Vector3f& lhs, const Vector3f& rhs) {
    if (
        lhs.x == rhs.x
        && lhs.z == rhs.z
        && lhs.y == rhs.y
        ){
        return true;
    }
    return false;
}

// **** Overloading of the operator [<<] OUTSIDE a Class (free function) **** //
std::ostream& operator<<(std::ostream& os, const Vector3f& obj){

    os << obj.x << ", " << obj.y << ", " << obj.z;

    return os;
}

int main(){
    // Object creation
    Vector3f my_vector_1;
    my_vector_1.x = 1.5f;
    my_vector_1.y = 2.5f;
    my_vector_1.z = 3.5f;

    Vector3f my_vector_2;
    my_vector_2.x = 3.5f;
    my_vector_2.y = 2.5f;
    my_vector_2.z = 1.5f;

    // Use of overloaded operator [==], parentheses are needed
    std::cout << (my_vector_1 == my_vector_2) << "\n";

    // Use of overloaded operator [+]
    my_vector_1 = my_vector_1 + my_vector_2;

    // Use of overloaded operator [<<]
    std::cout << my_vector_1 << "\n";
    
    // Use of overloaded operator [++]
    ++my_vector_1;
    std::cout << my_vector_1 << "\n";

    return 0;
}