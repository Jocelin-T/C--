#include <iostream>

// #################################### Class Data Layout ####################################
// Notes:   To simply optimizing a Class/Struct, set the members from the largest data type
//           to the lowest data type.
//          Alignment is in bytes what is the largest data type inside the Class/Struct.
//          The size of the Class/Struct is a multiple of the alignment.


struct NotOptimized{            // Total 24 bytes
    bool checkpoint;            // 1 byte + 3 padding
    double points;              // 8 bytes => alignment
    float score;                // 4 bytes
    short number_of_players;    // 2 bytes + 2 padding
};

struct Optimized{               // Total 16 bytes
    double points;              // 8 bytes => alignment
    float score;                // 4 bytes
    short number_of_players;    // 2 bytes
    bool checkpoint;            // 1 byte + 1 padding
};


int main(){

    NotOptimized no;
    std::cout << "boolean: " << sizeof(no.checkpoint) << " bytes\n";
    std::cout << "double: " << sizeof(no.points) << " bytes\n";
    std::cout << "float: " << sizeof(no.score) << " bytes\n";
    std::cout << "short: " << sizeof(no.number_of_players) << " bytes\n\n";
    std::cout << "Alignment Not Optimized: : " << alignof(no) << "bytes\n";
    std::cout << "Total Not Optimized: " << sizeof(no) << " bytes\n\n";

    Optimized o;
    std::cout << "Alignment Optimized: " << alignof(o) << "bytes\n";
    std::cout << "Total Optimized: " << sizeof(o) << " bytes\n";

    return 0;
}