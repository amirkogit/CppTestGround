#include "catch.hpp"
#include "../ds/node.h"
#include <iostream>
#include <memory>

TEST_CASE("Simple integer node test", "[Test1]")
{
    CoreDS::NodeInt node1;
    node1.setValue(10);

    CoreDS::NodeInt node2;
    node2.setValue(20);

    CoreDS::NodeInt node3;
    node3.setValue(30);

    node1.setNext(&node2);
    node2.setNext(&node3);

    CoreDS::printNode(&node1);
}

TEST_CASE("Simpe integer node test with pointers", "[Test1")
{
    using namespace CoreDS;
    using namespace std;

    auto node1 = make_unique<NodeInt>(25);
    auto node2 = make_unique<NodeInt>(44);
    auto node3 = make_unique<NodeInt>(36);
    auto node4 = make_unique<NodeInt>(78);
    node1->setNext(node2.get());
    node2->setNext(node3.get());
    node3->setNext(node4.get());

    printNode(node1.get());

}
