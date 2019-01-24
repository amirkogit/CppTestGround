#pragma once

#include "node.h"
#include <iostream>
#include <memory>

namespace CoreDS {

using namespace std;

template<typename T>
class SinglyLinkedListSmart final
{
public:
    SinglyLinkedListSmart() : m_count(0) {}

    unique_ptr<Node<T>> get(int index);

    void insertHead(T value);
    void insertTail(T value);
    void insert(T value, int index);

    int search(T value);

    void removeHead();
    void removeTail();
    void removeAt(int index);

    int count() const { return m_count; }
    void printList();

private:
    unique_ptr<Node<T>> m_head;
    unique_ptr<Node<T>> m_tail;
    int m_count;
};

// Get the item with the given index value
template<typename T>
unique_ptr<Node<T>> SinglyLinkedListSmart<T>::get(int index)
{
    if(index < 0 || index > m_count) {
        return nullptr;
    }

    auto node = m_head;

    for(int i = 0; i < index; ++i) {
        node = node->getNext();
    }

    return node;
}

// Insert the item at the beginning of the list
template<typename T>
void SinglyLinkedListSmart<T>::insertHead(T value)
{
    auto node = make_unique<Node<T>>(value);
    node->setNext(m_head);
    m_head = std::move(node);

    if(m_count == 0) {
        m_tail = m_head;
    }

    m_count++;
}

// Print the list
template<typename T>
void SinglyLinkedListSmart<T>::printList()
{
    using namespace std;

    auto node = m_head;
    while(node != nullptr) {
        cout << node->getValue() << " -> ";
        node = node->getNext();
    }

    cout << "NULL" << endl;
}

}
