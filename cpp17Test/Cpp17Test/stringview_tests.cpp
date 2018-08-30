#include "catch.hpp"
#include <iostream>
#include <string_view>

namespace StringView {
int run()
{
    std::cout << "StringView Demo\n";

    std::string_view str_view("abcd");

    auto begin = str_view.begin();
    auto cbegin = str_view.cbegin();

    std::cout << *begin << '\n';
    std::cout << *cbegin << '\n';

    std::cout << std::boolalpha << (begin == cbegin) << '\n';
    std::cout << std::boolalpha << (*begin == *cbegin) << '\n';

    std::cout << "\n";
    return 0;
}
} // end namespace

TEST_CASE("StringView test", "[stringview_tests]") {
    REQUIRE(StringView::run() == 0);
}
