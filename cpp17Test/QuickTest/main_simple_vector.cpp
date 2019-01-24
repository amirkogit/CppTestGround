// basic usage of vector class

#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// print the content of vector
void printVector(vector<int> values)
{
    for(auto const& elem : values) {
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "std::vector usage example application\n";

    std::vector<int> numbers {2,-7,45,990,23,45,2,1,0,-32};
    printVector(numbers);

    cout << "sort the given vector from less to greater\n";
    sort(begin(numbers), end(numbers));
    printVector(numbers);

    cout << "sort the given vector from greater to lesser\n";
    sort(begin(numbers), end(numbers), std::greater<int>());
    printVector(numbers);

    cout << "copy one vector to other\n";
    std::vector<int> numbersCopy = numbers;
    printVector(numbersCopy);

    return a.exec();
}
