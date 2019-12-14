#include "strucbind1.hpp"
#include <iostream>

int main()
{
    Customer c {"Tim", "Starr", 42};
    auto [f,l,v] = c;

    std::cout << "f/l/v: " << f << ' ' <<  l << ' ' << v << '\n';

    // modify structured bindings:
    std::string s { std::move(f) };
    l = "Walters";
    v += 10;
    std::cout << "f/l/v: " << f << ' ' <<  l << ' ' << v << '\n';
    std::cout << "c: " << c.getFirst() << ' ' << c.getLast() << ' ' << c.getValue() << '\n';
    std::cout << "s: " << s << '\n';
}