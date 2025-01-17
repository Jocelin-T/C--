#pragma once

#include "IState.hpp"
#include "Context.hpp"

#include <iostream>

class ConcreteStateA : public IState {
public:
    ConcreteStateA() {
        std::cout << "State (A) created" << '\n';
    }
    ~ConcreteStateA() {
        std::cout << "State (A) destroyed" << '\n';
    }

    void handle(void) override {
        std::cout << "State (A) handle" << '\n';
    }
};