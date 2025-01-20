#pragma once

#include "IStrategy.hpp"

#include <iostream>

class ConcreteStrategyB : public IStrategy {
public:
    ConcreteStrategyB() {
        std::cout << "ConcreteStrategyB created" << '\n';
    }
    ~ConcreteStrategyB() {
        std::cout << "ConcreteStrategyB destroyed" << '\n';
    }

    void execute(int data) override {
        m_data = data;
        std::cout << "ConcreteStrategyB executed with data: " << m_data << '\n';
    }

private:
    int m_data{ 0 };
};