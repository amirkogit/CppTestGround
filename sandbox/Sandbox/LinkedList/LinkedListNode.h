#pragma once
#include <memory>
#include <string>
#include <iostream>

namespace LinkedList {

template <typename T>
class LinkedListNode {
public:
    explicit LinkedListNode(T value)
    : _value(value){

    }

    LinkedListNode() {}

    T GetValue() { return _value;}

    std::shared_ptr<LinkedListNode<T>> GetNext()
    {
        return _next;
    }

    void SetNext(std::shared_ptr<LinkedListNode<T>>& next)
    {
        _next = next;
    }

private:
    T _value;
    std::shared_ptr<LinkedListNode<T>> _next;
};

template<typename T>
void PrintList(std::shared_ptr<LinkedListNode<T>>& node)
{
    while (node != nullptr) {
        std::cout << node->GetValue() << std::endl;
        node = node->GetNext();
    }
}

// TODO: do template specialization for std::string
//template<>
//void PrintList<std::string>(std::shared_ptr<LinkedListNode<std::string>>& node)
//{
//    while (node != nullptr) {
//        std::cout << node->GetValue().c_str() << std::endl;
//        node = node->GetNext();
//    }
//}
} // end of namespace