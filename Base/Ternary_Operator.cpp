#include <iostream>
#include <string>

// #################################### Ternary operator ####################################
// ternary operator ?: replacement to an if/else
// condition ? expression1 : expression2;
int main(){
    int grade = 75;
    grade >= 60 ? std::cout << "You pass\n" : std::cout << "You fail\n";
    // or like that:
    std::cout << (grade >= 80 ? "You Pass" : "You Fail");

    return 0;
}