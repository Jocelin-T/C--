#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// #################################### Read Files ####################################
// Notes:   Need to launch the .exe to read a file.
//          NEED to close the file at the end.
//          Possible to use std::stoi (string to int),
//           std::stof (string to float), etc... to transform the data type

int main(int argc, char* argv[]){

    // Program arguments (when launching with console)
    std::cout << "Arguments count: " << argc << "\n";

    // There is always 1 argument
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

        // Read data (Parsing data)
        std::cout << "File Content: \n"; 
        while (getline(input_file, line)) { 
            if(line[0] == '#'){
                // Ignore lines starting with #
            }
            else{
                // Construct a string stream form our line
                std::stringstream stream(line);
                // Break out each individual componenet
                //  based off delimiters (white space , ; /)
                std::string chunk;
                while(stream >> chunk){
                    std::cout << chunk << "\n"; // Print the current line 
                }
            }
        } 
    }
    
    input_file.close();

    return 0;
}