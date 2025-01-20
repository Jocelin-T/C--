#pragma once

#include "IStrategy.hpp"

#include <iostream>

class ConcreteStrategyDefault : public IStrategy {
public:
    ConcreteStrategyDefault() {
        std::cout << "ConcreteStrategyDefault created" << '\n';
    }
    ~ConcreteStrategyDefault() {
        std::cout << "ConcreteStrategyDefault destroyed" << '\n';
    }
    
    void execute(int data = 0) override {
        std::cout << "ConcreteStrategyDefault executed with data: " << m_data << '\n';
    }

private:
    int m_data{ 0 };
};