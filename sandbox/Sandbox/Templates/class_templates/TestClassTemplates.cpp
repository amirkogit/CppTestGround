#include <iostream>
#include <string>
#include <memory>

#include "ClassTemplates.hpp"
#include "MyClass.h"

using namespace std;

// rename to main() to run this as a main program
int mainTestClassTemplates()
{
    // test with stack of ints
    using IntStack = MyStack<int>;
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
    catch (const std::exception& ex ) {
        std::cerr << "Exception: " << ex.what() << endl;
    }

    // test with stack of strings
    using StringStack = MyStack<string>;
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
    catch(const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << endl;
    }

    // test with custom classes
    using MyClassStack = MyStack<MyClass>;
    MyClassStack class_stack;
    try {
        cout << names_stack.isEmpty() << endl;              // returns 1(True) as stack is empty
        class_stack.push(MyClass(101, "classname1"));       // push first item
        class_stack.push(MyClass(201, "classname2"));       // push second item
        cout << class_stack.isEmpty() << endl;              // returns 0(False) as stack is non-empty
        cout << class_stack.top().getClassName() << endl;   // returns classname2
        class_stack.pop();                                  // removes classname2
        cout << class_stack.top().getClassName() << endl;   // returns classname1
        class_stack.pop();                                  // removes classname1
        cout << class_stack.isEmpty() << endl;              // returns 1(True) as stack is empty now
        cout << class_stack.top().getClassName() << endl;   // as stack is empty, will throw exception
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << endl;
    }

    // test with custom classes but storing them as shared pointers
    using MyClassStackSharedPtr = MyStack<shared_ptr<MyClass>>;
    MyClassStackSharedPtr myclass_stack_sp;
    try {
        cout << myclass_stack_sp.isEmpty() << endl;                     // returns 1(True) as stack is empty
        myclass_stack_sp.push(make_shared<MyClass>(300, "class300"));   // push first item
        myclass_stack_sp.push(make_shared<MyClass>(400, "class400"));   // push second item
        cout << myclass_stack_sp.isEmpty() << endl;                     // returns 0(False) as stack is non-empty
        cout << myclass_stack_sp.top()->getClassName() << endl;         // returns class400
        myclass_stack_sp.pop();                                         // removes class400
        cout << myclass_stack_sp.top()->getClassName() << endl;         // returns class300
        myclass_stack_sp.pop();                                         // removes class300
        cout << myclass_stack_sp.isEmpty() << endl;                     // returns 1(True) as stack is empty now
        cout << myclass_stack_sp.top()->getClassName() << endl;         // as stack is empty, will throw exception

    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << endl;
    }

    getchar();
    return 0;
}