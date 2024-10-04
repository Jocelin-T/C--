#include <iostream>
#include <span>
#include <array>
#include <vector>

/* #################################### std::span ####################################
* Notes:    std::span can be use on any container, dynamic (like vector) or static (like array)
            Even if it's possible to modifiy a container explored by std::span, it's must be
             use like a view, std::span doesn't take the ownership of the container.
            It has 2 members:   - "T" a pointer to the container
                                - "Extent" the number of elements if static, else the dynamic_extent
*/          

// Normal way to print an array
void printArray(const std::array<int, 4>& param){
    for(const int& elem : param){
        std::cout << elem << '\n';
    }
}

// Print an array be using std::span, not required to give the size
void printIntegerContainer(const std::span<int>& param){

    // Can check if the container is static or dynamic
    if(param.extent == std::dynamic_extent){
        std::cout << "Dynamic container\n";
    }
    else{
        std::cout << "Static container\n";
    }

    for(const int& elem : param){
        std::cout << elem << '\n';
    }
}


int main(){

    std::array<int, 4> arr {1,2,3,4};
    printArray(arr);
    printIntegerContainer(arr);
    
    std::cout << "----------------\n";

    std::span my_span{arr};
    std::cout << my_span.extent << " elements in this container\n";

    std::cout << "----------------\n";

    std::vector<int> my_vector{1,2,3,4,5,6,7};
    printIntegerContainer(my_vector);

    return 0;
}