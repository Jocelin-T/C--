#include <iostream>
#include <fstream>

// #################################### Create and Write Files ####################################
// Notes:   Need to launch the .exe to create a file.
//          

int main(){

    // File creation
    // With .open the file will be override
    std::ofstream out_file;
    out_file.open("textfile.txt");

    // Write inside the file
    out_file << "Here some text\n";
    out_file << "Here another row\n";
    out_file << 45 << 065 << 0.5 << "\n";

    // Once done, need to close the file
    out_file.close();

    return 0;
}