#pragma once

#include "Memento.hpp"
#include "Originator.hpp"

#include <iostream>
#include <vector>

// Has a composition of Memento (diamond arrow)
class Caretaker {
public:
    Caretaker(Originator& originator)
        : m_originator{ originator }
    {
        std::cout << "Caretaker Created\n";
    }

    // Save the current state of the Originator by creating a Memento
    void pushState(void) {
        Memento state = m_originator.createState();
        m_memento_stats.emplace_back(state);
    }

    // Restore the last state of the Originator by using the last Memento
    void popState(void) {

        if (m_memento_stats.empty()) {
            return;
        }

        m_originator.restoreState(m_memento_stats.back());
        m_memento_stats.pop_back();
    }

    // For debug
    void printStates(void) const {
        int index{ 0 };
        std::cout   << "------------------\n";
        for (const auto& memento : m_memento_stats) {
            std::cout   << "(" << index << ") Title: " << memento.getTitle() 
                        << " || Value: " << memento.getValue() 
                        << '\n';
            index++;
        }
        std::cout   << "------------------\n";
    }

private:
    std::vector<Memento> m_memento_stats;
    Originator& m_originator; // Carefull it's a reference
};