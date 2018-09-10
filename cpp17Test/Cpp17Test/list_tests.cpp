#include "catch.hpp"
#include "../ds/list.h"
#include <iostream>

TEST_CASE("SimpleList Tests", "[test1]")
{
    using namespace std;

    CoreDS::SimpleList myList;
    REQUIRE(myList.getCount() == 0);

    // insert few items
    myList.insert(0,20);
    myList.insert(1,40);
    myList.insert(2,50);
    myList.insert(3,60);
    myList.insert(4,70);

    REQUIRE(myList.getCount() == 5);

    // remove from the last
    myList.remove(4);
    myList.remove(3);
    myList.remove(2);
    myList.remove(1);
    myList.remove(0);

    REQUIRE(myList.getCount() == 0);

    std::cout << "End of insert() and remove() test. " << endl;
}

TEST_CASE("SimpleList Tests1", "[test2]")
{
    using namespace std;

    // initialize the list
    auto myList = CoreDS::SimpleList();

    // insert few items
    myList.insert(0,20);
    myList.insert(1,40);
    myList.insert(2,50);
    myList.insert(3,60);
    myList.insert(4,70);

    // print the current list
    myList.print();

    // insert some items in the middle of the list
    cout << "Inserting 44 and 66 at index 2\n";
    myList.insert(2,44);
    myList.insert(2,66);

    // print the list again
    myList.print();

    // search the value 66
    cout << "Search element 66" << endl;
    int result = myList.search(66);
    REQUIRE(result == 2);
    if(result == -1) {
        cout << "66 is not in the list.";
    }
    else {
        cout << "66 found in the list at the index " << result;
    }
    cout << endl << endl;

    // Search the value 88
    result = myList.search(88);
    REQUIRE(result == -1);

    // remove index 2
    cout << "Removing element at index 2" << endl;
    myList.remove(2);
    myList.print();
    cout << "Current count: " << myList.getCount() << endl;

    myList.empty();
    result = myList.getCount();
    REQUIRE(result == 0);
    cout << "Current count: " << myList.getCount() << endl;
}
