#pragma once

#include "node.h"
#include <iostream>

namespace CoreDS {

template<typename T>
class SinglyLinkedList final
{
public:
    SinglyLinkedList() : m_head(nullptr), m_tail(nullptr), m_count{0} {}

    Node<T>* get(int index);

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
    Node<T>* m_head;
    Node<T>* m_tail;
    int m_count;
};

// Get the item with the given index value
template<typename T>
Node<T>* SinglyLinkedList<T>::get(int index)
{
    if(index < 0 || index > m_count) {
        return nullptr;
    }

    Node<T>* node = m_head;

    for(int i = 0; i < index; ++i) {
        node = node->getNext();
    }

    return node;
}

// Insert the item at the beginning of the list
template<typename T>
void SinglyLinkedList<T>::insertHead(T value)
{
    auto node = new Node<T>(value);
    node->setNext(m_head);
    m_head = node;

    if(m_count == 0) {
        m_tail = m_head;
    }

    m_count++;
}

// Insert the item at the tail of the list
template<typename T>
void SinglyLinkedList<T>::insertTail(T value)
{
    if(m_count == 0) {
        insertHead(value);
        return;
    }

    auto node = new Node<T>(value);

    m_tail->setNext(node);

    m_tail = node;

    m_count++;
}

// Insert the item at the given index
template<typename T>
void SinglyLinkedList<T>::insert(T value, int index)
{
    // check if the index is out of bound
    if(index < 0 || index > m_count) {
        return;
    }

    // insert a new head
    if(index == 0) {
        insertHead(value);
        return;
    }
    // insert a new tail
    else if(index == m_count) {
        insertTail(value);
        return;
    }

    // find the previous node from head
    auto prevNode = m_head;

    // traverse the elements until the selected index is found
    for(int i = 0; i < index - 1; ++i) {
        prevNode = prevNode->getNext();
    }

    // create the next node that is element after the previous node
    auto nextNode = prevNode->getNext();

    // create a new node
    auto node = new Node<T>(value);

    // insert this new node between the previous node and the next node
    node->setNext(nextNode);

    prevNode->setNext(node);

    m_count++;
}

// Get the index of the selected item
template<typename T>
int SinglyLinkedList<T>::search(T value)
{
    if(m_count == 0) {
        return -1;
    }

    int index {0};

    auto node = m_head;
    while(node->getValue() != value) {
        index++;
        node = node->getNext();

        if(node == nullptr) {
            return -1;
        }
    }

    return index;
}

// Remove the head item
template<typename T>
void SinglyLinkedList<T>::removeHead()
{
    if(m_count == 0) {
        return;
    }

    auto node = m_head;

    m_head = m_head->getNext();

    delete node;

    m_count--;
}

// Remove the tail item
template<typename T>
void SinglyLinkedList<T>::removeTail()
{
    if(m_count == 0) {
        return;
    }

    if(m_count == 1) {
        removeHead();
        return;
    }

    // find the previous node
    auto prevNode = m_head;

    // candidate node to be removed
    auto node = m_head->getNext();

    // traverse the elements until the last element
    while(node->getNext() != nullptr) {
        prevNode = prevNode->getNext();
        node = node->getNext();
    }

    // prevNode now becomes the tail
    prevNode->setNext(nullptr);
    m_tail = prevNode;

    // safe to remove the last item now
    delete node;

    m_count--;
}

// Remove the item at the given index
template<typename T>
void SinglyLinkedList<T>::removeAt(int index)
{
    if(m_count == 0) {
        return;
    }

    if(index < 0 || index >= m_count) {
        return;
    }

    // remove the current head
    if(index == 0) {
        removeHead();
        return;
    }
    // remove the current tail
    else if(index == m_count - 1) {
        removeTail();
        return;
    }

    // traverse the node from the head
    auto prevNode = m_head;

    // find the node before the selected index
    for(int i = 0; i < index - 1; ++i) {
        prevNode = prevNode->getNext();
    }

    // removed element is after the prevNode
    auto node = prevNode->getNext();

    auto nextNode = node->getNext();

    prevNode->setNext(nextNode);

    // now its safe to delete the node
    delete node;

    m_count--;
}

// Print the SinglyLinkedList
template<typename T>
void SinglyLinkedList<T>::printList()
{
    using namespace std;

    Node<T>* node = m_head;
    while(node != nullptr) {
        cout << node->getValue() << " -> ";
        node = node->getNext();
    }

    cout << "NULL" << endl;
}

}

