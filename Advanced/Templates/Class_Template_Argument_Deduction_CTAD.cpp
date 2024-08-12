#include <iostream>

// #################################### Class Template Argument Deduction (CTAD) ####################################
// Notes:   CTAD don't need template arguments


template<typename first, typename second>
struct Entry{
    Entry(first key, second value) : m_key(key), m_value(value){

    }
    
    first m_key;
    second m_value;
};




int main(){

    Entry entry(5, 100.1f); // will work but better to specify

    std::cout << entry.m_key << "\n";
    std::cout << entry.m_value << "\n";

    return 0;
}
