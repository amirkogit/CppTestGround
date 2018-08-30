#include "catch.hpp"
#include <iostream>
#include <set>
#include <iomanip>

namespace StructuredBindings {
int run()
{
    std::cout << "Structured Bindings Demo\n";

    std::set<std::string> myset;
    if (auto [iter, success] = myset.insert("Hello"); success)
        std::cout << "insert is successful. The value is " << std::quoted(*iter) << '\n';
    else
        std::cout << "The value " << std::quoted(*iter) << " already exists in the set\n";

    std::cout << "\n";
    return 0;
}
}

TEST_CASE("Structured Bindings test", "[structured_bindings]") {
    REQUIRE(StructuredBindings::run() == 0);
}



