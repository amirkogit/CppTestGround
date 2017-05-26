#pragma once
#include <iostream>
#include <memory>

namespace NodeChains {

class Node
{
public:
    explicit Node(int value)
        : m_value(value) {}
    ~Node() {}

    int getValue() { return m_value; }

    std::shared_ptr<Node> getNext()
    {
        return m_next;
    }

    void setNext(std::shared_ptr<Node>& next)
    {
        m_next = next;
    }

private:
    int m_value;
    std::shared_ptr<Node> m_next;
};

void printNodeChains(std::shared_ptr<Node>& node)
{
    auto temp = node; 
    while (temp != nullptr) {
        std::cout << temp->getValue() << std::endl;
        temp = temp->getNext();
    }
}
} // end of namespace
