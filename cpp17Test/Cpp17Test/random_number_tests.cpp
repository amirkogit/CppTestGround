#include "catch.hpp"
#include <iostream>
#include <random>

namespace RandomNumbers {

//Select five numbers from 1 to 69 for the white balls; then select one number from 1 to 26 for the red Powerball.

int run()
{
    std::cout << "Random numbers demo\n";

    std::random_device rd {};
    auto mtgen = std::mt19937 {rd()};
    auto ud = std::uniform_int_distribution<>{1,69};

    // select five numbers for white balls
    std::cout << "Five numbers for white ball: ";

    for(auto i = 0; i < 5; ++i) {
        auto number = ud(mtgen);
        std::cout << number << " ";
    }

    std::cout << "\n";

    std::cout << "Powerball number: " << ud(mtgen) << "\n";

    return 0;
}

} // end namespace


TEST_CASE("Random Number Generation Test", "[random_test]") {

    const int TRIALS = 10;

    for(int trial = 0; trial < TRIALS; ++trial) {
        REQUIRE(RandomNumbers::run() == 0);
    }
}
