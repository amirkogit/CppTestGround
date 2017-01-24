#pragma once
#include "LinkedListNode.h"

namespace LinkedList {

template<typename T, 
         template<typename> typename LinkedListNode = LinkedListNode>
class LinkedList
{
public:
    LinkedList()
        : _count(0) {}

    ~LinkedList() {}

    void AddFirst(T value);

    int GetCount() { return _count;}

private:
    void AddFirst(std::shared_ptr<LinkedListNode<T>>& node);

private:
    std::shared_ptr<LinkedListNode<T>> _head;
    std::shared_ptr<LinkedListNode<T>> _tail;
    int _count;
};

template<typename T, 
         template<typename> typename LinkedListNode = LinkedListNode>
void LinkedList<T, LinkedListNode>::AddFirst(T value)
{
    auto new_node = std::make_shared<LinkedListNode<T>>(value);
    AddFirst(new_node);
}

template<typename T,
    template<typename> typename LinkedListNode = LinkedListNode>
void LinkedList<T, LinkedListNode>::AddFirst(std::shared_ptr<LinkedListNode<T>>& node)
{
    std::shared_ptr<LinkedListNode<T>> temp = _head;
    
    // point head to the new node
    _head = node;
    
    // insert rest of the list behind the head
    _head->SetNext(temp);
    
    _count++;
    
    if (_count == 1) {
        _tail = _head;
    }
}

} // end of namespace