#pragma once

#include "IState.hpp"
#include "Context.hpp"

#include <iostream>

class ConcreteStateDefault : public IState {
public:
    ConcreteStateDefault() {
        std::cout << "State (Default) created" << '\n';
    }
    ~ConcreteStateDefault() {
        std::cout << "State (Default) destroyed" << '\n';
    }

    void handle(void) override {
        std::cout << "State (Default) handle" << '\n';
    }
};