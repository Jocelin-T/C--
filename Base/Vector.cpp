// #include <iostream>
#include <vector>
// #include <string>

// #################################### Recursion ####################################
// Notes:   When using vector it's possible to reserve memory space, 
//          who reduce the performances cost.
//          

int main(){
    // Cost 36 allocations
    std::vector<int> my_arrays_1;
    for(int i = 0; i < 10; i++){
        int temp(i);
        my_arrays_1.push_back(std::move(temp));
    }

    // Cost 13 allocations
    std::vector<int> my_arrays_2;
    my_arrays_2.reserve(10); // reserve 10 slots of int size in the memory
    for(int i = 0; i < 10; i++){
        int temp(i);
        my_arrays_2.push_back(std::move(temp));
    }
}