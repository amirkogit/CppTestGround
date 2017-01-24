#include <iostream>
#include "NodeChains.h"
#include "LinkedListNode.h"
#include "LinkedList.h"

void NodeChainsDemo()
{
    auto first = std::make_shared<NodeChains::Node>(10);
    auto middle = std::make_shared<NodeChains::Node>(20);
    auto last = std::make_shared<NodeChains::Node>(30);

    first->SetNext(middle);
    middle->SetNext(last);

    NodeChains::PrintNodeChains(first);
}

void LinkedListNodeDemoWithString()
{
    auto first = 
        std::make_shared<LinkedList::LinkedListNode<std::string>>("Node1");

    auto middle =
        std::make_shared<LinkedList::LinkedListNode<std::string>>("Node2");

    auto last =
        std::make_shared<LinkedList::LinkedListNode<std::string>>("Node3");

    first->SetNext(middle);
    middle->SetNext(last);

    while (first != nullptr) {
        std::cout << first->GetValue().c_str() << std::endl;
        first = first->GetNext();
    }
}

void LinkedListNodeDemoWithInt()
{
    auto first =
        std::make_shared<LinkedList::LinkedListNode<int>>(110);
    auto middle =
        std::make_shared<LinkedList::LinkedListNode<int>>(220);
    auto last =
        std::make_shared<LinkedList::LinkedListNode<int>>(330);
    
    first->SetNext(middle);
    middle->SetNext(last);

    LinkedList::PrintList(first);
}

void LinkedListNodeDemoWithDouble()
{
    auto first =
        std::make_shared<LinkedList::LinkedListNode<double>>(110.256);
    auto middle =
        std::make_shared<LinkedList::LinkedListNode<double>>(220.587);
    auto last =
        std::make_shared<LinkedList::LinkedListNode<double>>(330.778);

    first->SetNext(middle);
    middle->SetNext(last);

    LinkedList::PrintList(first);
}

void LinkedListDemo()
{
    auto node =
        std::make_shared<LinkedList::LinkedList<int>>();
    node->AddFirst(10);
    node->AddFirst(20);
    node->AddFirst(30);

    std::cout << "Count = " << node->GetCount();
}

int main()
{
    //NodeChainsDemo();

    //LinkedListNodeDemoWithString();

    //LinkedListNodeDemoWithInt();

    //LinkedListNodeDemoWithDouble();

    LinkedListDemo();

    getchar();
    return 0;
}