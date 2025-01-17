#pragma once

#include "Memento.hpp"

#include <string>
#include <iostream>

// Has a dependency on Memento (dotted line arrow)
class Originator {
public:
    Originator(void) {
        std::cout << "Originator Created\n";
    }

    Memento createState(void) {
        std::cout << "m_title: " << m_title << " || m_value: " << m_value << '\n';
        return Memento(m_title, m_value);
    }

    void restoreState(const Memento& state) {
        m_title = state.getTitle();
        m_value = state.getValue();
    }

    std::string m_title{ "No Title" };
    int m_value{ 0 };
};