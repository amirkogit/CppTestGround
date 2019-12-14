#include <iostream>
#include <complex>

// example 1
struct Data {
    std::string name;
    double value;
};

struct MoreData : Data {
    bool done;
};

// example 2
struct CData {
    const char* name;
    double value {0.0};
};

struct CppData : Data {
    bool critical {false};

    void print() const {
        std::cout << '[' << name << ',' << value << ']' << " : " << critical << '\n';
    }
};

// example 3: aggregates from multiple base classes
template<typename T>
struct D : std::string, std::complex<T>
{
    std::string data;
};

// example 4: 
struct Base {
    friend struct Derived;

private: 
    Base() {

    }
};

struct Derived : Base {

};


// ---------------------------------------------------------------------------------
int main()
{
    // Example 1
    Data x { "test", 3.14};
    std::cout << x.name << " " << x.value << '\n';

    // possible with C++17
    MoreData y { {"test1", 2.45}, false };
    std::cout << y.name << " " << y.value << " " << y.done << '\n';

    // can also skip the nested braces
    MoreData z { "test2", 45.66, true };
    std::cout << z.name << " " << z.value << " " << z.done << '\n';

    // Example 2
    CppData m { {"cppdata", 4.5}, false };
    m.print();

    CppData x1 {}; 
    x1.print();
    
    CppData x2 {{"msg"}}; // warning: missing initializer for member ‘Data::value’ [-Wmissing-field-initializers]
    x2.print();

    CppData x3 {{}, true};
    x3.print();

    CppData x4; // has an unspecified value
    x4.print();

    // Example 3
    D<float> s1 { {"thing1"}, {3.2,4.6}, "hello" }; // string,complex,data
    D<float> s2 { "thing2", {1.2,3.2}, "world" };
    std::cout << s1.data << '\n';
    //std::cout << s1 << '\n'; // ERROR
    std::cout << static_cast<std::complex<double>>(s1) << '\n';
    std::cout << static_cast<std::string>(s1) << '\n';

    // checks wether it's an aggregate
    std::cout << std::is_aggregate<decltype(s1)>::value << '\n';
    std::cout << std::is_aggregate<decltype(x1)>::value << '\n';

    // Example 4: following does not compile
    //Derived d1 {}; // ERROR since C++17
    Derived d2;
}