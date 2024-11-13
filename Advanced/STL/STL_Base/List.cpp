#include <iostream>
#include <list>

/* #################################### std::list ####################################
* Notes:    std::list is a doubly-linked list, the elements are not one after the others
             in the memory (like array or vector), but the element is link with a pointer,
             who point to the next and previous elements.
            It's better to use it when the container size is constantly modified.
            It's bad to use it when we need to access a precise element, 
             because we need to traverse all elements before the one we want.
*/

void printList(const std::list<int>& list){
    
    std::cout << "---------------\n";
    for (const int& elem : list) {
        std::cout << elem << ", ";    
    }
    std::cout << '\n';
}


int main(){

    std::list<int> my_list;

    // Add an element
    my_list.push_back(1);
    my_list.push_back(2);
    my_list.push_back(3);
    my_list.push_back(4);
    printList(my_list);

    // Insert an element before the position (insert(position, value))
    my_list.insert(begin(my_list), 0);
    my_list.insert(end(my_list), 5);
    printList(my_list);

    // Advance the iterator a specific number of steps
    // cbegin => constant begin
    auto iterator{cbegin(my_list)};
    iterator = std::next(iterator, my_list.size() / 2);
    my_list.insert(iterator, 9);
    printList(my_list);

    // Older way to advance trought a std::list
    iterator = cbegin(my_list);
    std::advance(iterator, my_list.size() / 2);
    std::cout << "Middle is: " << *iterator << '\n';
    
    // Sort the std::list
    my_list.sort();
    printList(my_list);

    

    return 0;
}