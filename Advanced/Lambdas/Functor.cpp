#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>


// #################################### Function Object (functor) ####################################
// Notes:   Functor is a function with state.

struct Value{
    int m_result_1{0};
    float m_result_2{0};

    int operator()(int new_result){
        m_result_1 = new_result;
        return new_result;
    }

    float operator()(float new_result){
        m_result_2 = new_result;
        return new_result;
    }
};

// 
struct Goblin{
    int m_health;
    int m_strength;

    Goblin(int h, int s) : m_health(h), m_strength(s){}

    // Limited operator overloading, can't compare strength
    bool operator<(const Goblin& rhs){
        return this->m_health < rhs.m_health;
    }
};

// Functor inside Struct
struct GoblinComperator{
    bool operator()(const Goblin& lhs, const Goblin& rhs){
        return lhs.m_strength < rhs.m_strength;
    }
};

int main(){

    Value v;
    v(42);
    v(42.73f); 
    std::cout << v.m_result_1 << "\n";
    std::cout << v.m_result_2 << "\n";

    std::vector<Goblin> goblins{Goblin(32,25),Goblin(5,30),Goblin(95,10)};

    // Compare the health
    std::cout << "----- Sort by HP -----\n";
    std::sort(std::begin(goblins), std::end(goblins));
    for(auto g : goblins){
        std::cout << "h:" << g.m_health << " s: " << g.m_strength << "\n";
    }
    std::cout << "----- Sort by STR -----\n";
    // Compare the strength, because of functor in parameter
    std::sort(std::begin(goblins), std::end(goblins), GoblinComperator());
    for(auto g : goblins){
        std::cout << "h:" << g.m_health << " s: " << g.m_strength << "\n";
    }

    return 0;
}