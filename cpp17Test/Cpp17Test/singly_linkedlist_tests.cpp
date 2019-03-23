#include "catch.hpp"
#include "./ds/singlylinkedlist.h"
#include <iostream>
#include <memory>

TEST_CASE("SinglyLinkedListTest - ints", "[Test1]")
{
    using namespace CoreDS;
    using namespace std;

    cout << "\n[Start] SinglyLinkedListTest - ints\n";

    auto linkedList = make_unique<SinglyLinkedList<int>>();

    cout << ">> empty linked list\n";
    linkedList->printList();

    cout << ">> inserting 5 at head\n";
    linkedList->insertHead(5);
    linkedList->printList();

    cout << ">> inserting 90 at head\n";
    linkedList->insertHead(90);
    linkedList->printList();

    cout << ">> inserting 67 at tail\n";
    linkedList->insertTail(67);
    linkedList->printList();

    cout << ">> inserting -56 at tail\n";
    linkedList->insertTail(-56);
    linkedList->printList();

    cout << ">> inserting 20 at index 3\n";
    linkedList->insert(20, 3);
    linkedList->printList();

    cout << ">> inserting 4 at index 1\n";
    linkedList->insert(4, 1);
    linkedList->printList();

    cout << ">> inserting 4 again at head\n";
    linkedList->insertHead(4);
    linkedList->printList();

    cout << ">> index of 67: " << linkedList->search(67) << "\n";
    cout << ">> index of 4: " << linkedList->search(4) << "\n";
    cout << ">> index of 555: " << linkedList->search(555) << "\n";
    cout << ">> index of -56: " << linkedList->search(-56) << "\n";

    int totalCount = linkedList->count();
    cout << ">> total count: " << totalCount << "\n";

    cout << ">> removing head\n";
    linkedList->removeHead();
    linkedList->printList();

    REQUIRE(linkedList->count() == totalCount - 1);

    cout << ">> removing tail\n";
    linkedList->removeTail();
    linkedList->printList();

    cout << ">> removing tail again\n";
    linkedList->removeTail();
    linkedList->printList();

    cout << ">> removing at index 2\n";
    linkedList->removeAt(2);
    linkedList->printList();

    cout << ">> removing at index 999\n";
    linkedList->removeAt(999);
    linkedList->printList();

    cout << ">> removing at index 0\n";
    linkedList->removeAt(0);
    linkedList->printList();

    cout << " removing at index 1\n";
    linkedList->removeAt(1);
    linkedList->printList();

    REQUIRE(linkedList->count() == 1);

    cout << " removing tail\n";
    linkedList->removeTail();
    linkedList->printList();

    REQUIRE(linkedList->count() == 0);

    cout << ">> total count: " << linkedList->count() << "\n";

    cout << "[End] SinglyLinkedListTest - ints\n";
}

TEST_CASE("SinglyLinkedListTest - string", "[Test2]")
{
    using namespace CoreDS;
    using namespace std;

    // Test String: A quick brown fox jumps over the bridge

    cout << "\n[Start] SinglyLinkedListTest - string\n";

    auto linkedList = make_unique<SinglyLinkedList<string>>();

    cout << ">> empty linked list\n";
    linkedList->printList();

    cout << ">> inserting 'quick' at head\n";
    linkedList->insertHead("quick");
    linkedList->printList();

    cout << ">> inserting 'A' at head\n";
    linkedList->insertHead("A");
    linkedList->printList();

    cout << ">> inserting 'the' at tail\n";
    linkedList->insertTail("the");
    linkedList->printList();

    cout << ">> inserting 'bridge' at tail\n";
    linkedList->insertTail("bridge");
    linkedList->printList();

    // A -> quick -> the -> bridge -> NULL
    cout << " >> inserting 'brown' at index 2\n";
    linkedList->insert("brown", 2);
    linkedList->printList();

    cout << " >> inserting 'fox' at index 3\n ";
    linkedList->insert("fox", 3);
    linkedList->printList();

    cout << " >> inserting 'jumps' at index 4\n ";
    linkedList->insert("jumps", 4);
    linkedList->printList();

    cout << " >> inserting 'over' at index 5\n ";
    linkedList->insert("over", 5);
    linkedList->printList();

    cout << " >> index of 'fox': " << linkedList->search("fox") << "\n";
    cout << " >> index of 'bridge': " << linkedList->search("bridge") << "\n";
    cout << " >> index of 'nostring': " << linkedList->search("nostring") << "\n";

    int totalCount = linkedList->count();
    cout << ">> total count: " << totalCount << "\n";

    cout << ">> removing head\n";
    linkedList->removeHead();
    linkedList->printList();

    REQUIRE(linkedList->count() == totalCount - 1);

    cout << ">> removing tail\n";
    linkedList->removeTail();
    linkedList->printList();

    cout << ">> removing tail again\n";
    linkedList->removeTail();
    linkedList->printList();

    cout << ">> removing at index 2\n";
    linkedList->removeAt(2);
    linkedList->printList();

    cout << ">> removing at index 999\n";
    linkedList->removeAt(999);
    linkedList->printList();

    cout << ">> removing at index 0\n";
    linkedList->removeAt(0);
    linkedList->printList();

    cout << " removing at index 1\n";
    linkedList->removeAt(1);
    linkedList->printList();

    REQUIRE(linkedList->count() == 2);

    cout << " removing tail\n";
    linkedList->removeTail();
    linkedList->printList();

    REQUIRE(linkedList->count() == 1);

    cout << " removing head\n";
    linkedList->removeHead();
    linkedList->printList();

    REQUIRE(linkedList->count() == 0);

    cout << ">> total count: " << linkedList->count() << "\n";

    cout << "[End] SinglyLinkedListTest - string\n";
}
