#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <cassert>

template<class Container>
int count(const Container& container)
{
    int sum = 0;
    for (auto&& elem : container ) {
        sum += 1;
    }
    return sum;
}


template<class Container, class Predicate>
int count_if(const Container& container, Predicate pred)
{
    int sum = 0;
    for (auto&& elem : container) {
        if (pred(elem)) {
            sum += 1;
        }
    }
    return sum;
}

template<class Container>
void print_elements(const Container& container)
{
    std::cout << "Elements of container are:\n";

    for (auto&& elem : container) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> v {3,1,4,5,6,8,2,3,15,22};
    assert(count(v) == 10);
    std::cout << "Count = " << count(v) << std::endl;
    print_elements(v);

    int number_greater = count_if(v, [](int e) { return e > 5; });
    std::cout << "Number greater than 5: " << number_greater << "\n";

    int number_lesser = count_if(v, [](int e) { return e < 3; });
    std::cout << "Number lesser than 3: " << number_lesser << "\n";

    return a.exec();
}
