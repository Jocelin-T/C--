#pragma once

#include <iostream>

class IStrategy {
public:
    IStrategy(void) {
        std::cout << "IStrategy created" << '\n';
    }
    virtual ~IStrategy() {
        std::cout << "IStrategy destroyed" << '\n';
    }
    
    virtual void execute(int data) = 0;
};