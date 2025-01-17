#pragma once

#include "IState.hpp"

#include <iostream>

class ConcreteStateB : public IState {
public:
    ConcreteStateB() {
        std::cout << "State (B) created" << '\n';
    }
    ~ConcreteStateB() {
        std::cout << "State (B) destroyed" << '\n';
    }

    void handle(void) override {
        std::cout << "State (B) handle" << '\n';
    }
};