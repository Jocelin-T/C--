#pragma once

#include "IState.hpp"
#include "ConcreteStateDefault.hpp"

#include <utility>
#include <memory>

class Context {
public:
    Context(void) 
        : m_p_state(std::make_unique<ConcreteStateDefault>()) 
    {
        std::cout << "Context created" << '\n';
    }
    ~Context() {
        std::cout << "Context destroyed" << '\n';
    }

    void setState(std::unique_ptr<IState> p_new_state) {
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


