#pragma once

#include <iostream>

namespace CoreDS {
class NodeInt final
{
public:
    NodeInt();
    NodeInt(int value);
    ~NodeInt();
    void setValue(int value) { m_value = value; }
    int getValue() { return m_value; }
    void setNext(NodeInt* node) { m_next = node; }
    NodeInt* getNext() { return m_next; }

private:
    int m_value;
    NodeInt* m_next = nullptr;
};

static void printNode(NodeInt* node)
{
    using namespace std;

    while(node != nullptr) {
        cout << node->getValue() << " -> ";
        node = node->getNext();
    }
    cout << "NULL" << endl;
}
}

