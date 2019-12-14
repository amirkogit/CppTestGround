#include<iostream>

// Mandatory copy elision for temporaries
class MyClass {
public:
    MyClass() {
        std::cout << "+++ MyClass() constructor called.\n";
    }

    ~MyClass() {
        std::cout << "--- ~MyClass() destructor called.\n";
    }

    // Disable copy and move support
    MyClass(const MyClass&) = delete;
    MyClass(MyClass&&) = delete;
};

void foo(MyClass param) {
    std::cout << "Inside foo()\n";
}

MyClass bar() {
    std::cout << "Inside bar()\n";
    return MyClass {}; // returns temporary
}

// without copy and move support, following will not compile
// Here, a variable obj has a name and so Named Return Value Optimization(NRVO) kicks in that still requires copy/move support
// MyClass foo2()
// {
//     MyClass obj;
//     return obj; // still requires copy/move support
// }


// another example: classes with explicitly deleted move constructor
class CopyOnly {
public:
    CopyOnly() {

    }

    CopyOnly(int) {

    }

    CopyOnly(const CopyOnly&) = default;

    CopyOnly(CopyOnly&&) = delete; // explicitly deleted
};

CopyOnly ret() {
    return CopyOnly {};
}

CopyOnly ret2() {
    CopyOnly co;
    return co;
}

//----------------------------------------------------------------------------
int main()
{
    foo(MyClass {});
    MyClass x = bar();
    foo(bar());

    CopyOnly co = 42; // OK since C++17
}