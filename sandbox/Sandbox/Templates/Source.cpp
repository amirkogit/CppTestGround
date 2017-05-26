#include <iostream>
#include "Max.hpp"
#include <string>


void Max_Test()
{
    std::cout << "Max(4,5): " << Max(4, 5) << std::endl;
    std::cout << "Max(3.56,6.45): " << Max(3.56, 6.45) << std::endl;

    std::cout << "Max(3.56,6.45): " << Max<double>(3.56, 6.45) << std::endl;

    std::string s1 = "algorithms";
    std::string s2 = "datastructures";
    std::cout << "Max(s1,s2): " << Max(s1, s2) << std::endl;
}

// rename the function to main() to run this as a main program
int mainTest()
{
    Max_Test();

    getchar();
    return 0;
}