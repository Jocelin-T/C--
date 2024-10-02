#include <iostream>
#include <array>

/* #################################### std::array ####################################
* Notes:    Fixed size
*           Allocated on the Stack
            Safer than [] 
*/


// C-style method to print the size of an array size
void printArray(int array[4], int size){
    std::cout << sizeof(int) * size << '\n';
}

// STL array
void printArraySTL(std::array<int, 4> param){
    std::cout << sizeof(param) << '\n'; // more safe compare to C-style
    std::cout << param.size() << '\n'; // return the number of elements
    std::cout << param.at(2) << '\n'; // return the value (like [2])
}

// Still possible to access underline element, like pointer
void lecacyCCodeBase(int* array, int size){

}

int main(){

    // static, C-style arrays
    int arr[4];
    int init[] {1, 2, 3};

    std::cout << sizeof(arr) << '\n';
    printArray(arr, 4);

    // STL style array
    std::array<int, 4> arr_stl {1,2,3,4};
    printArraySTL(arr_stl);

    // .data() is like passing the pointer of the array
    lecacyCCodeBase(arr_stl.data(), arr_stl.size());


    return 0;
}