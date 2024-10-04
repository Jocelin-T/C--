#include <iostream>
#include <vector>

/* #################################### std::vector ####################################
* Notes:    std::vector is a dynamic array, so he can be resize at run time.
            vector is heap allocated, better when storing very large data
*/

int main(){

    std::vector<int> my_vector{1,2,3,4,5};

    // .capacity() return the number of element that the vector CAN hold
    std::cout << "Capacity: " << my_vector.capacity() << '\n';

    // .push_back() add the data to the end of the vector
    my_vector.push_back(6);
    std::cout << "Capacity: " << my_vector.capacity() << '\n';
    my_vector.push_back(7);
    std::cout << "Capacity: " << my_vector.capacity() << '\n';

    my_vector.emplace_back();

    // .reserve() manually resize the number of element that the vector CAN hold 
    my_vector.reserve(20);
    std::cout << "Capacity: " << my_vector.capacity() << '\n';

    // .shrink_to_fit() resize the vector by freeing the unused space allocated to him
    my_vector.shrink_to_fit();
    std::cout << "Capacity: " << my_vector.capacity() << '\n';

    // .begin() and .end() return the iterator(ptr) (NOT the index) of an element vector
    // my_vector.begin();
    // my_vector.begin() + 1; // give the seconde element iterator(ptr)
    // my_vector.end();

    std::cout << "----------------\n";
    // .erase() remove an element, BUT need an iterator(ptr), not an index. 
    //  DON'T use it in foreach loop
    my_vector.erase(my_vector.begin()); // cost a lot to use
    std::cout << "Capacity: " << my_vector.capacity() << '\n';

    std::cout << "----------------\n";
    for(size_t i {0}; i < my_vector.size(); i++){
        // .at() is like the operator[]
        std::cout << my_vector.at(i) << '\n';
    }

    std::cout << "----------------\n";
    // .data() return the pointer of the vector
    std::cout << my_vector.data();

    return 0;
}