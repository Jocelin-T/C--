#include <iostream>
#include <string>

// #################################### Array ####################################
int main(){
    // ****************************** Fill an array with user input ******************************
    std::string numbers[5];
    int size = sizeof(numbers)/sizeof(numbers[0]);
    std::string temp;

    for(int i = 0; i < size; i++){
        std::cout << "Enter a number or [Q] to quit. N°" << i+1 << ": ";
        std::getline(std::cin, temp); // string is place in a temp variable in case of quit
        if(temp == "q" || temp == "Q"){ // need the same type (string)
            break;
        }
        else{ // apply the temp to array
            numbers[i] = temp;
        }
    }

    std::cout << "You choose this numbers:\n";
    // this for loop while not display empty index of the array
    for(int i = 0; !numbers[i].empty(); i++){
        std::cout << numbers[i] << "\n";
    }

    return 0;
}
