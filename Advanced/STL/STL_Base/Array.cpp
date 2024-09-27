#include <iostream>

// #################################### std::array ####################################
// Notes:   


void printArray(int array[4]){
    std::cout << sizeof(array) << '\n';
}

int main(){

    // static, C-style arrays
    int data[4];
    int init[] {1, 2, 3};

    std::cout << sizeof(data) << '\n';

    printArray(data);

    return 0;
}