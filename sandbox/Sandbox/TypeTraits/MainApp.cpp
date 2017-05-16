#include <iostream>
#include <type_traits>
#include <memory>

using namespace std;

//////////////////////////////////////////////////////////

template <typename T>
void foo(const T& val)
{
    if (std::is_pointer<T>::value) {
        cout << "foo() called for a pointer." << endl;
    }
    else {
        cout << "foo() called for a value." << endl;
    }
}

class Image {};

void basicTest()
{
    foo(3);

    Image* img;
    foo(img);

    Image& img_ref = *img;
    foo(img_ref);

    shared_ptr<Image> img_sp;
    foo(img_sp);
}

///////////////////////////////////////////////////////////


class ObjectA {
public:
    void defaultImplementation() {
        cout << "called ObjectA::defaultImplementation" << endl;
    }
};  

class ObjectB {
public:
    void optimisedImplementation() {
        cout << "called ObjectB::optimisedImplementation" << endl;
    }
};

class ObjectC {
public:
    void defaultImplementation() {
        cout << "called ObjectC::defaultImplementation" << endl;
    }
};

// default trait class
template<typename T>
struct supports_optimised_implementation {
    static const bool value = false;
};

// specialized version
template<>
struct supports_optimised_implementation<ObjectB> {
    static const bool value = true;
};

template<bool b>
struct algorithm_selector {
    template<typename T>
    static void implementation(T& object) {
        // implement algorithm operating on object here...
        object.defaultImplementation();
    }
};

// specialization of algorithm_selector
template<>
struct algorithm_selector<true> {
    template<typename T>
    static void implementation(T& object) {
        object.optimisedImplementation();
    }
};

template<typename T>
void invokeAlgorithm(T& object)
{
    algorithm_selector<supports_optimised_implementation<T>::value> ::implementation(object);
}

int main()
{
    ObjectA a;
    invokeAlgorithm(a); // calls default implementation

    ObjectB b;
    invokeAlgorithm(b); // calls the optimised implementation

    ObjectC c;
    invokeAlgorithm(c);

    getchar();
    return 0;
}