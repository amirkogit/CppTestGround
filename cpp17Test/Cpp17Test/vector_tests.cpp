#include "catch.hpp"
#include <iostream>

TEST_CASE("size and resize of std::vector", "[vector]") {

    std::vector<int> v(10);

    REQUIRE(v.size() == 10);
    REQUIRE(v.capacity() == 10);

    SECTION("resizing bigger changes size and capacity") {
        v.resize(20);

        REQUIRE(v.size() == 20);
        REQUIRE(v.capacity() >= 20);
    }

    SECTION("resizing smaller changes size but not capacity") {
        v.resize(0);

        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 10);
    }
}
