#pragma once

#include <string>
#include <iostream>

// A memento must be unchanged once created
class Memento {
public:
    Memento(const std::string& title, const int value)
        : m_title{ title }, m_value{ value }
    {
        std::cout << "Memento Created with title: " << m_title 
                  << " and value: " << m_value << '\n';
    }

    std::string getTitle(void) const {
        return m_title;
    }

    int getValue(void) const {
        return m_value;
    }

private:
    std::string m_title{ "No Title" };
    int m_value{ 0 };
};