#pragma once

#include "IStrategy.hpp"

#include <iostream>

class ConcreteStrategyA : public IStrategy {
public:
    ConcreteStrategyA() {
        std::cout << "ConcreteStrategyA created" << '\n';
    }
    ~ConcreteStrategyA() {
        std::cout << "ConcreteStrategyA destroyed" << '\n';
    }

    void execute(int data) override {
        m_data = data;
        std::cout << "ConcreteStrategyA executed with data: " << m_data << '\n';
    }

private:
    int m_data{ 0 };
};