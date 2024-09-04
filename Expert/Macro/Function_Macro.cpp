#include <iostream>
#include <source_location> // C++ 20

// #################################### Functions in Macro ####################################
// Notes:   Helpfull for debugging, create a function 
//          Function given has parameter is still call.
//          Here some build in function:
//           __FILE__       => return the file where this function is located (can be replace by source_location)
//           __LINE__       => return the line where this function is called (can be replace by source_location)

//          Use "\" to indicate a new line like this: 
//           #define LOG(param) \
//           std::cout << "LOG: " \
//           << #param; param; \
//           std::cout << "\n";
           


#define LOG(param) std::cout << "LOG: " << #param; param; std::cout << "\n";
#define DEBUG 1

int add(int a, int b){
    int result {a + b};

    #if DEBUG // when DEBUG is 1 (true)
    std::cout << __LINE__ << " : " << __FILE__ << "\n";
    #endif

    

    std::cout << "Result is: " << result << "\n";
    return result;
}


int main(){

    // #ifdef is needed, or there will be useless call
    #if DEBUG // if DEBUG is 1 (true)

    // Here how to use a Function in the macro
        LOG(add(2, 3);)

    #else // if DEBUG is 0 (false)
        add(2, 3);

    #endif

    return 0;
}