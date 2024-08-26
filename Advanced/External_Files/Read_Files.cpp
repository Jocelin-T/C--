#include <iostream>
#include <fstream>
#include <string>

// #################################### Read Files ####################################
// Notes:   Need to launch the .exe to read a file.
//          

int main(int argc, char* argv[]){

    // Program arguments (when launching with console)
    std::cout << "argc: " << argc << "\n";

    if(argc < 2){
        std::cout << "Missing file name\n";
        return 0;
    }

    for(int i = 0; i < argc; i++){
        std::cout << "\t" << argv[i] << "\n";
    }

    // File object
    std::ifstream input_file;
    input_file.open(argv[1]);

    // If file manage to open
    if(input_file.is_open()){
        std::cout << "File open\n";
        
        // Temp storage for each line
        std::string line;

        // Read data
        std::cout << "File Content: \n"; 
        while (getline(input_file, line)) { 
            std::cout << line << "\n"; // Print the current line 
        } 

    }
    
    input_file.close();

    return 0;
}