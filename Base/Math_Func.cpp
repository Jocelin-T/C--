#include <iostream>
#include <math.h>

// #################################### Math Functions ####################################
int main(){
    double x = 3;
    double y = 4;
    double z;

    // Get the min or max
    z = std::max(x, y);
    std::cout << z << "\n";
    z = std::min(x, y);
    std::cout << z << "\n";

    // Power 
    z = pow(2, 4);
    std::cout << z << "\n";

    // Square Root
    z = sqrt(9);
    std::cout << z << "\n";

    // Abstraction
    z = abs(-3);
    std::cout << z << "\n";

    // Rounded
    z = round(3.14);
    std::cout << z << "\n";

    // Celling
    z = ceil(3.14);
    std::cout << z << "\n";

    // Floor
    z = floor(3.14);
    std::cout << z << "\n";

    return 0;
}