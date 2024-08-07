#include <iostream>
#include <vector>
#include <string>

// #################################### Typedef and using ####################################
// typedef = is a keyword used to create an additionnal name for another data type (Alias) 
// Reduce the typo
// Convention is add "_t" to the end of the new name (t for type)
typedef std::vector<std::pair<std::string, int>> pairlist_t; // Real exemple
typedef std::string text_t; // Simpler exemple

// using = is a keyword who work better with templates and is used more today and work the same
using text_t = std::string;

int main(){

    pairlist_t var_pairlist;
    text_t name = "hello";

    std::cout << name << "\n";

    return 0;
}