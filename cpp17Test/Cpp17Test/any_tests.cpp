#include "catch.hpp"
#include <iostream>
#include <any>

namespace Any {
int run()
{
    std::cout << "Any Demo\n";

    // simple example
    auto a = std::any(12);

    std::cout << std::any_cast<int>(a) << '\n';

    try {
        std::cout << std::any_cast<std::string>(a) << '\n';
    }
    catch(const std::bad_any_cast& e) {
        std::cout << e.what() << '\n';
    }

    // advanced example

    a = std::string("hello");

    auto& ra = std::any_cast<std::string&>(a); //< reference
    ra[1] = 'o';

    std::cout << "a: "
        << std::any_cast<const std::string&>(a) << '\n'; //< const reference

    auto b = std::any_cast<std::string&&>(std::move(a)); //< rvalue reference

    // Note: 'b' is a move-constructed std::string,
    // 'a' is left in valid but unspecified state

    std::cout << "a: " << *std::any_cast<std::string>(&a) //< pointer
        << "b: " << b << '\n';

    std::cout << "\n";
    return 0;
}
} // end namespace

TEST_CASE("Any test", "[any_tests]") {
    REQUIRE(Any::run() == 0);
}

