#pragma once
#include <memory>
#include <string>
#include <iostream>

namespace LinkedList {

template <typename T>
class LinkedListNode {
public:
    explicit LinkedListNode(T value)
    : m_value(value){

    }

    LinkedListNode() {}

    T getValue() { return m_value;}

    std::shared_ptr<LinkedListNode<T>> getNext()
    {
        return m_next;
    }

    void setNext(std::shared_ptr<LinkedListNode<T>>& next)
    {
        m_next = next;
    }

private:
    T m_value;
    std::shared_ptr<LinkedListNode<T>> m_next;
};

template<typename T>
void printList(std::shared_ptr<LinkedListNode<T>>& node)
{
    auto temp = node;
    while (temp != nullptr) {
        std::cout << temp->getValue() << std::endl;
        temp = temp->getNext();
    }
}
} // end of namespace