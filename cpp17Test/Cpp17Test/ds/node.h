#pragma once

#include <iostream>

namespace CoreDS {

// Simple node data structure that can hold only integer values
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

static void printNodeInt(NodeInt* node)
{
    using namespace std;

    while(node != nullptr) {
        cout << node->getValue() << " -> ";
        node = node->getNext();
    }
    cout << "NULL" << endl;
}

// Generic node data structure that can hold any types
template<typename T>
class Node {
public:
    Node(T value) : m_value(value), m_next(nullptr) {}
    ~Node() { }
    T getValue() { return m_value; }
    void setNext(Node<T>* node) { m_next = node; }
    Node<T>* getNext() { return m_next; }

private:
    T m_value;
    Node<T>* m_next = nullptr;
};

template<typename T>
static void printNode(Node<T>* node)
{
    using namespace std;

    while(node != nullptr) {
        cout << node->getValue() << " -> ";
        node = node->getNext();
    }
    cout << "NULL" << endl;
}
}

