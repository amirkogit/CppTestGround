#include "catch.hpp"
#include <iostream>
#include <variant>

namespace MonoState {
struct S
{
    S(int i) : i(i) {}
    int i;
};

int run()
{
    std::cout << "MonoState Demo\n";

    // Without the monostate type this declaration will fail.
    // This is because S is not default-constructible.

    std::variant<std::monostate, S> var;

    // var.index() is now 0 - the first element
    // std::get<S> will throw! We need to assign a value

    var = 12;

    std::cout << std::get<S>(var).i << '\n';

    std::cout << "\n";
    return 0;
}
} // end namespace

TEST_CASE("Monostate test", "[monostate_tests]") {
    REQUIRE(MonoState::run() == 0);
}
