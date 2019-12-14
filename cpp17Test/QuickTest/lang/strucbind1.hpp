#include "customer1.hpp"
#include <utility>

// provide a tuple like API for class Customer for structured bindings
template<>
struct std::tuple_size<Customer> {
    static constexpr int value = 3;
};

template<>
struct std::tuple_element<2, Customer> {
    using type = long;
};

template<std::size_t Idx>
struct std::tuple_element<Idx, Customer> {
    using type = std::string;
};

// old method: defining corresponding getters as overloads of a function get<>()
// template<std::size_t> auto get(const Customer& c);
// template<> auto get<0>(const Customer& c) { return c.getFirst(); }
// template<> auto get<1>(const Customer& c) { return c.getLast(); }
// template<> auto get<2>(const Customer& c) { return c.getValue(); }

// new method : using compile-time if feature
template<std::size_t I> auto get(const Customer& c) {
    static_assert(I < 3);

    if constexpr (I == 0) {
        return c.getFirst();
    }
    else if constexpr (I == 1) {
        return c.getLast();
    }
    else {
        return c.getValue();
    }
}