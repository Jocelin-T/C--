#pragma once

#include "IStrategy.hpp"
#include "ConcreteStrategyDefault.hpp"

#include <iostream>
#include <utility>
#include <memory>

class Context {
public:
    Context(void)
        // Possible to use a default strategy
        : m_p_strategy(std::make_unique<ConcreteStrategyDefault>())
    {
        std::cout << "Context created" << '\n';
    }
    ~Context() {
        std::cout << "Context destroyed" << '\n';
    }

    // Passed by reference when using std::move (rValue) to avoid useless copy
    void setStrategy(std::unique_ptr<IStrategy>&& p_strategy) {
        m_p_strategy = std::move(p_strategy);
    }

    void executeStrategy(int data) {
        m_p_strategy->execute(data);
    }

private:
    std::unique_ptr<IStrategy> m_p_strategy{ nullptr };
    // IStrategy& m_strategy;
};