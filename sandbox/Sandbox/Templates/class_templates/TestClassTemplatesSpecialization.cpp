#include<iostream>
#include "ClassTemplatesSpecialization.hpp"

using namespace std;

int main()
{
    // test with stack of strings
    using StringStack = MyStackSpecialization<string>;

    try {
        StringStack s1;
        StringStack s2;
        s1.push("hello");
        s1.push("world");

        s2 = s1; // calls copy assignment operator

        cout << s1.isEmpty() << endl;   // returns 0 (False)

        StringStack s3;
        s3 = std::move(s1); // calls the move assignment operator if there is one
                            // if it move assignment operatior is not defined then 
                            // calls assignment operator instead

                            
        cout << s1.isEmpty() << endl;   // returns 1 (True) because s1 has been moved
        cout << s3.top() << endl;       // returns world
        cout << s1.top() << endl;       // throws exception

    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << endl;
    }

    // test with stack of string - part 2
    StringStack names_stack;
    try {
        cout << names_stack.isEmpty() << endl;    // returns 1(True) as stack is empty
        names_stack.push("John");                 // push first item
        names_stack.push("Mike");                 // push second item
        cout << names_stack.isEmpty() << endl;    // returns 0(False) as stack is non-empty
        cout << names_stack.top() << endl;        // returns Mike
        names_stack.pop();                        // removes Mike
        cout << names_stack.top() << endl;        // returns John
        names_stack.pop();                        // removes John
        cout << names_stack.isEmpty() << endl;    // returns 1(True) as stack is empty now
        cout << names_stack.top() << endl;        // as stack is empty, will throw exception
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << endl;
    }

    // test with stack of ints
    using IntStack = MyStackSpecialization<int>;
    IntStack item_ids;
    try {
        cout << item_ids.isEmpty() << endl;    // returns 1(True) as stack is empty
        item_ids.push(10);                     // push first item
        item_ids.push(20);                     // push second item
        cout << item_ids.isEmpty() << endl;    // returns 0(False) as stack is non-empty
        cout << item_ids.top() << endl;        // returns 20
        item_ids.pop();                        // removes 20
        cout << item_ids.top() << endl;        // returns 10
        item_ids.pop();                        // removes 10
        cout << item_ids.isEmpty() << endl;    // returns 1(True) as stack is empty now
        cout << item_ids.top() << endl;        // as stack is empty, will throw exception
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << endl;
    }

    getchar();
    return 0;
}