#include <cstring>
#include <iostream>


// #################################### Reinterpret Casting ####################################
// Notes:   Reinterpret_cast literaly interpret the bytes as whatever type you decide 
//           to threat the raw bytes. 
//          Used with void pointer too.

struct GameState{
    int level;
    int health;
    int points;
    bool game_complete;
    bool boss_defeated;
};

int main(){

    float pi = 3.14f;

    // C-Style cast
    // Can work, but can get some errors
    std::cout << (int)(pi) << "\n";

    // Dereference reinterpret_cast (to have a value) the int pointer (<int*>) 
    //  to whatever is at the address of pi (&pi).
    std::cout << *reinterpret_cast<int*>(&pi) << "\n";
    std::cout << *reinterpret_cast<float*>(&pi) << "\n";

    //*** Example use 1 ***//
    // Key idea is 1 read from disk to get all data.

    // Load some game state
    GameState gs = {66, 100, 999, false, true};

    // Allocate some memory
    char bag_of_bytes[sizeof(GameState)];

    // Let's just store some data structure into "bag of bytes"
    std::memcpy(bag_of_bytes, &gs, sizeof(GameState));
    std::cout << *(bag_of_bytes) << "\n"; // will return "B" who is "66" in ASCII
    std::cout << *((int*)bag_of_bytes) << "\n"; // this will work but not clear

    // Here how to read the data properly
    std::cout << *reinterpret_cast<int*>(bag_of_bytes) << "\n";
    std::cout << *reinterpret_cast<int*>(bag_of_bytes+4) << "\n";
    std::cout << *reinterpret_cast<int*>(bag_of_bytes+8) << "\n";
    std::cout << *reinterpret_cast<bool*>(bag_of_bytes+12) << "\n";
    std::cout << *reinterpret_cast<bool*>(bag_of_bytes+13) << "\n";

    // Better way to do the same
    GameState gs2 = *reinterpret_cast<GameState*>(bag_of_bytes); 
    std::cout << gs2.level << "\n";
    std::cout << gs2.health << "\n";
    std::cout << gs2.points << "\n";
    std::cout << gs2.game_complete << "\n";
    std::cout << gs2.boss_defeated << "\n";

    return 0;
}