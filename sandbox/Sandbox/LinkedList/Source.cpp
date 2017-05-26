#include <iostream>
#include "NodeChains.h"
#include "LinkedListNode.h"
#include "LinkedList.h"

void nodeChainsDemo()
{
    auto first = std::make_shared<NodeChains::Node>(10);
    auto middle = std::make_shared<NodeChains::Node>(20);
    auto last = std::make_shared<NodeChains::Node>(30);

    first->setNext(middle);
    middle->setNext(last);

    NodeChains::printNodeChains(first);
}

void linkedListNodeDemoWithString()
{
    auto first = 
        std::make_shared<LinkedList::LinkedListNode<std::string>>("Node1");

    auto middle =
        std::make_shared<LinkedList::LinkedListNode<std::string>>("Node2");

    auto last =
        std::make_shared<LinkedList::LinkedListNode<std::string>>("Node3");

    first->setNext(middle);
    middle->setNext(last);

   
    std::cout << "using printList()\n";
    LinkedList::printList(first);
   
    std::cout << "Printing with usual method\n";
    while (first != nullptr) {
        std::cout << first->getValue().c_str() << std::endl;
        first = first->getNext();
    }
}

void linkedListNodeDemoWithInt()
{
    auto first =
        std::make_shared<LinkedList::LinkedListNode<int>>(110);
    auto middle =
        std::make_shared<LinkedList::LinkedListNode<int>>(220);
    auto last =
        std::make_shared<LinkedList::LinkedListNode<int>>(330);
    
    first->setNext(middle);
    middle->setNext(last);

    LinkedList::printList(first);
}

void linkedListNodeDemoWithDouble()
{
    auto first =
        std::make_shared<LinkedList::LinkedListNode<double>>(110.256);
    auto middle =
        std::make_shared<LinkedList::LinkedListNode<double>>(220.587);
    auto last =
        std::make_shared<LinkedList::LinkedListNode<double>>(330.778);

    first->setNext(middle);
    middle->setNext(last);

    LinkedList::printList(first);
}

void linkedListDemo()
{
    auto node =
        std::make_shared<LinkedList::LinkedList<int>>();
    node->addFirst(10);
    node->addFirst(20);
    node->addFirst(30);

    std::cout << "Count = " << node->getCount();
}

int main()
{
    nodeChainsDemo();

    linkedListNodeDemoWithString();

    linkedListNodeDemoWithInt();

    linkedListNodeDemoWithDouble();

    linkedListDemo();

    getchar();
    return 0;
}