#include <iostream>
#include <string>
#include <algorithm>

template <typename Type>
Type Add(Type const& lhs, Type const& rhs)
{
    return lhs + rhs;
}

template <typename Lhs, typename Rhs>
auto Add_2(Lhs lhs, Rhs rhs) -> decltype(lhs + rhs) 
{
    return lhs + rhs;
}

template<typename Type, size_t Size>
Type Sum(Type const (&array)[Size])
{
    Type tp {};

    for(size_t idx = 0; idx < Size; idx++) {
        tp += array[idx];
    }

    return tp;
}

int main()
{
    std::cout << "Templates demo" << std::endl;
    std::cout << "----------------" << std::endl;

    std::cout << "Add(2,3) = " << Add(2,3) << std::endl;
    std::cout << "Add(2.3,3.3) = " << Add(2.3,3.3) << std::endl;
   
   // this will not compile!
   // std::cout << "Add(2.3,3) = " << Add(2.3,3) << std::endl;

   // but this will compile because we passed explicit <double>
    std::cout << "Add(2.3,3) = " << Add<double>(2.3,3) << std::endl;

    // this works correctly as expected
    std::cout << "Add_2(2.3,3) = " << Add_2(2.3,3) << std::endl;
    
    std::string const& first = "hello";
    std::string const& second = "world";
    std::cout << "Add('hello','world') = " << Add(first,second) << std::endl;

    int values[10] = {0};
    std::fill_n(values, 6, 2);
    std::cout << "Sum(values) = " << Sum(values) << std::endl;

    return 0;
}