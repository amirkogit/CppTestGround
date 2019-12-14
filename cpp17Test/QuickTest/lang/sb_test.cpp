// -------------------------------------------------------------------------
// Test code snippets from C++17 - The complete quide book
// Compile and run:
//      g++ -Wall -Wextra -Wno-unused -std=c++17 -o test main_cxx17cg.cpp -lthread && ./test
//
// -------------------------------------------------------------------------

#include <iostream>
#include <map>
#include <array>

namespace structure_bindings {
struct MyStruct {
    int i = 0;
    std::string s;
};

MyStruct getStruct() {
    return MyStruct { 42, "hello world"};
}

void test() {
    auto [id, val] = getStruct();
    std::cout << id << " " << val << "\n";

    // iterating over the map
    std::map<int,std::string> entries = {
        { 100, "John"},
        { 200, "Mark"},
        { 300, "Karl"}
    };

    for (const auto& [key, value] : entries) {
        std::cout << key << " : " << value << '\n';
    }

    MyStruct ms { 43, "california"};
    auto [u,v] = ms;
    ms.i = 77;
    std::cout << u << '\n'; // prints 43
    u = 99;
    std::cout << ms.i << '\n'; // prints 99
    std::cout << "v= " << v << "  ms.s = " << ms.s << '\n';

    // move semantics
    {
        MyStruct ms = { 33, "Jim"};
        auto && [v,n] = std::move(ms);
        std::cout << "ms.s = " << ms.s << '\n';
        std::cout << "n = " << n << '\n'; 
    }

    // structures and classes
    {
        struct B {
            int a = 1;
            int b = 2;
        };

        struct D1 : B {

        };
        auto [x,y] = D1 {}; // OK

        struct D2 : B {
            int c = 3;
        };
        //auto [i, j ,k] = D2 {}; // ERROR - compile error
    }

    // Raw arrays
    {
        int arr[] = {34, 56};
        auto [x,y] = arr; // OK
        std::cout << "x= " << x << " y= " << y << '\n';
        //auto [z] = arr; // ERROR: number of elements doesn't fit
    }

    // std::array
    {
        std::array<int,4> arr = {4,1,2,-2};
        //auto [a,b] = arr; // ERROR: number of elements doesn't fit
        auto [a,b,c,d] = arr;
        std::cout << "a,b,c,d = " << a << " " << b << " " << c << " " << d << '\n';
        std::cout << "contents of arr = " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << '\n';

        a += 10; b += 10; c += 10; d += 10; // content is not modified
        std::cout << "contents of arr = " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << '\n';

        auto& [m,n,o,p] = arr;
        m += 10; n += 10; // modifies the content
        std::cout << "contents of arr = " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << '\n';
    }

    // std::tuple
    {
        std::tuple<char, float, std::string> tup = {'c', 3.14, "circle"};
        std::cout << "tup = " << std::get<0>(tup) << " ,"  // Old way of accessing tuple
                              << std::get<1>(tup) << " ," 
                              << std::get<2>(tup) << '\n';
        auto [a,b,c] = tup; // new way of accessing tuple
        std::cout << "tup contents: " << a << " " << b << " " << c << '\n';
    }

    // std::pair
    {
        std::map<std::string, int> coll;
        auto [pos, ok] = coll.insert({"Jim", 42});
        if (!ok) {
            std::cout << "Insert operation failed.\n";
        }
        else {
            auto search = coll.find("Jim");
            std::cout << "(key,value) =  " << search->first << " " << search->second << '\n';
        }
    }


} // end of test()

} // end of namespace structure_bindings




// --------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    structure_bindings::test();
}
// --------------------------------------------------------------------------------------
