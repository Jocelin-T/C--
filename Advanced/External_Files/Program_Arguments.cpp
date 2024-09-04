#include <cstdlib>
#include <iostream>

// #################################### Program arguments ####################################
// Notes:   How to set arguments when launching the program.
//          argc    => count of argument, there is always one (the executable).
//          argv    => actuals argument store in an array.
//          env     => environment variables from the system


int main(int argc, char* argv[], char* env[]){
    // Other way to make the same main function:
    //  int main(int argc, char** argv, char** env){
    //  }

    std::cout << "Argument count: " << argc << "\n";

    // Missing arguments
    if(argc < 2){
        std::cout << "Missing arguments after the executable\n";
        // exit(1); // stop the program
    }

    for(int i = 0; i < argc; i++){
        std::cout << "[" << i << "]" << argv[i] << "\n";
    }

    // New way to explore environment variables
    std::cout << std::getenv("PATH") << "\n";

    // Old way to explore environment variables (don't work here):
    // std::cout << "\nEnvironment: " << *env <<"\n";
    // int i = 0;
    // for(;;){
    //     std::cout << env[i];
    //     if (env[i] == nullptr){
    //         break;
    //     } 
    // }

    return 0;
}