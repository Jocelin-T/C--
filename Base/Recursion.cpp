#include <iostream>

// #################################### Recursion ####################################
void walk(int steps);
int main(){
    // recursion    =   a programming technique where a function
    //                  invokes itself from within break
    //                  a complex concept into a repeatable single step

    // advantages   =   less code and is cleaner
    //                  useful for sorting and searching algorithms
    // disavantages =   uses more memory
    //                  slower

    walk(100);

    return 0;
}
void walk(int steps){
    if(steps > 0){
        std::cout << "You take a step\n";
        walk(steps - 1); // recursive
    }
}