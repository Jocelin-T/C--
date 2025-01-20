#pragma once

#include "IState.hpp"
#include "ConcreteStateDefault.hpp"

#include <iostream>
#include <utility>
#include <memory>

class Context {
public:
    Context(void) 
        // Possible to use a default state
        : m_p_state(std::make_unique<ConcreteStateDefault>()) 
    {
        std::cout << "Context created" << '\n';
    }
    ~Context() {
        std::cout << "Context destroyed" << '\n';
    }
    
    // Passed by reference when using std::move (rValue) to avoid useless copy
    void setState(std::unique_ptr<IState>&& p_new_state) {
        m_p_state = std::move(p_new_state);
    }

    void handle(void) {
        if (m_p_state) {
            m_p_state->handle();
        }
    }

private:
    std::unique_ptr<IState> m_p_state{ nullptr };
};


