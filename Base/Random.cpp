#include <iostream>
#include <ctime> // Needed for random

// #################################### Random ####################################
int main(){
    // not totaly random
    // First the function need a "seed"
    // the current calander time is a good one:
    srand(time(NULL));

    int num = rand() % 6 + 1; // the int after the % is the max number, only if +1 is added 

    std::cout << num;


    return 0;
}