#pragma once
#include <iostream>
#include <memory>

namespace NodeChains {

class Node
{
public:
    explicit Node(int value)
        : _value(value) {}
    ~Node() {}

    int GetValue() { return _value; }

    std::shared_ptr<Node> GetNext()
    {
        return _next;
    }

    void SetNext(std::shared_ptr<Node>& next)
    {
        _next = next;
    }

private:
    int _value;
    std::shared_ptr<Node> _next;
};

void PrintNodeChains(std::shared_ptr<Node>& node)
{
    while (node != nullptr) {
        std::cout << node->GetValue() << std::endl;
        node = node->GetNext();
    }
}
} // end of namespace
