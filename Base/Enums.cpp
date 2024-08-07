#include <iostream>
// #################################### Enums ####################################
enum Day {  Monday = 0, Tuesday = 1, Wednesday = 2, 
            Thursday = 3, Friday = 4, Saturday = 5, 
            Sunday = 6}; // Don't forget ";" HERE

// In case no number are assigned to a enum,
// by default it's like a list (0, 1, 2, ect)

int main(){
    // enums =  a user-defined data type that consists
    //          of paired named-integer constants.
    //          GREAT if you have a set of potential options

    Day today = Monday; 

    // Only integer is accepted in a switch
    switch(today){ 
        case Monday:  std::cout << "It's Monday\n";
                        break;
        case Tuesday:  std::cout << "It's Tuesday\n";
                        break;
        case Wednesday:  std::cout << "It's Wednesday\n";
                        break;
        case Thursday:  std::cout << "It's Thursday\n";
                        break;
        case Friday:  std::cout << "It's Friday\n";
                        break;
        case Saturday:  std::cout << "It's Saturday\n";
                        break;
        case 6:  std::cout << "It's Sunday\n"; // Can also be the associate number
                        break;
    }

    return 0;
}