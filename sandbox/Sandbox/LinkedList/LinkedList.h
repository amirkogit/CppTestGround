#pragma once
#include "LinkedListNode.h"

namespace LinkedList {

template<typename T, 
         template<typename> typename LinkedListNode = LinkedListNode>
class LinkedList
{
public:
    LinkedList()
        : m_count(0) {}

    ~LinkedList() {}

    void addFirst(T value);

    int getCount() { return m_count;}

private:
    void addFirst(std::shared_ptr<LinkedListNode<T>>& node);

private:
    std::shared_ptr<LinkedListNode<T>> m_head;
    std::shared_ptr<LinkedListNode<T>> m_tail;
    int m_count;
};

template<typename T, 
         template<typename> typename LinkedListNode = LinkedListNode>
void LinkedList<T, LinkedListNode>::addFirst(T value)
{
    auto new_node = std::make_shared<LinkedListNode<T>>(value);
    addFirst(new_node);
}

template<typename T,
    template<typename> typename LinkedListNode = LinkedListNode>
void LinkedList<T, LinkedListNode>::addFirst(std::shared_ptr<LinkedListNode<T>>& node)
{
    std::shared_ptr<LinkedListNode<T>> temp = m_head;
    
    // point head to the new node
    m_head = node;
    
    // insert rest of the list behind the head
    m_head->setNext(temp);
    
    m_count++;
    
    if (m_count == 1) {
        m_tail = m_head;
    }
}

} // end of namespace