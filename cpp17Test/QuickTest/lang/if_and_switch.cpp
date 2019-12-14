#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> records = {
        {20, "Carl"},
        {23, "Zenith"}
    };

    std::cout << "if and switch with initialization\n";

    // lambda to print the content of map
    auto print_map = [&]() {
        std::cout << "Content of map:\n";
        for(const auto& [k,v] : records) {
            std::cout << k << " " << v << '\n';
        }
    };

    print_map();

    // if with initialization
    if (auto [pos, ok] = records.insert({23, "new-data"}); !ok) {
        const auto& [key,val] = *pos;
        std::cout << "key = " << key << " already exists: " << '\n';
    }

    if (auto[pos, ok] = records.insert({34, "Jack"}); ok) {
        const auto& [key,val] = *pos;
        std::cout << "key = " << key << " value = " << val << " added successfully.\n"; 
    }

    print_map();
}