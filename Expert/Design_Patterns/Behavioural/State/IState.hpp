#pragma once

#include <iostream>

class IState {
public:
    IState() {
        std::cout << "IState created" << '\n';
    }
    virtual ~IState() {
        std::cout << "IState destroyed" << '\n';
    }

    virtual void handle(void) = 0;
};