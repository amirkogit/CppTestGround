#include "catch.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace FileSystems {
namespace fs = std::filesystem;

int run()
{
    std::cout << "FileSystems Demo\n";

    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    for(auto& p: fs::directory_iterator("sandbox"))
        std::cout << p << '\n';
    fs::remove_all("sandbox");

    std::cout << "\n";
    return 0;
}
} // end namespace

TEST_CASE("Filesystems test", "[filesystem_tests]") {
    REQUIRE(FileSystems::run() == 0);
}


