//Find a pair with maximum product in array of Integers
//Given an array with both +ive and -ive integers, return a pair with highest product.
// Examples
//Input: arr[] = {1, 4, 3, 6, 7, 0}
//Output: {6,7}

//Input: arr[] = {-1, -3, -4, 2, 0, -5}
//Output: {-4,-5}

#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;

void printVector(const vector<int>& input)
{
    for(const auto& elem : input) {
        cout << elem << " ";
    }
    cout << endl;
}

// O(n^2) solution
void maxProductPairVer0(vector<int>& input)
{
    int size = input.size();
    if(size < 2) {
        cout << "No pair exists.\n";
        return;
    }

    // initialize max product pair
    int a = input[0];
    int b = input[1];

    // traverse through every possible pair
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(input[i] * input[j] > a * b) {
                a = input[i];
                b = input[j];
            }
        }
    }

    cout << "Max product pair: {" << a << "," << b << "}\n";
}

// O(n) solution
void maxProductPairVer1(vector<int> &input)
{
    // sort input array in ascending order
    sort(begin(input), end(input), greater<int>());
    printVector(input);

    int size = input.size();

    if(size < 2) {
        cout << "No pair exists.\n";
        return;
    }

    if(size == 2) {
        cout << "Max product pair: {" << input[0] << "," << input[1] << "}\n";
        return;
    }

    // get the product of first two and last two numbers
    int prod1 = input[0] * input[1];
    int prod2 = input[size-1] * input[size - 2];

    if(prod1 > prod2) {
        cout << "Max product pair: {" << input[0] << "," << input[1] << "}\n";
    }
    else {
        cout << "Max product pair: {" << input[size - 1] << "," << input[size - 2] << "}\n";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Max product in array of Integers\n";

    vector<int> v1 {1, 4, 3, 6, 7, 0};
    printVector(v1);
    maxProductPairVer0(v1);

    vector<int> v2 {-1, -3, -4, 2, 0, -5};
    printVector(v2);
    maxProductPairVer0(v2);

    cout << boolalpha;
    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<int>::max() << endl;
    cout << endl;

    vector<int> v3 = v1;
    maxProductPairVer1(v3);

    vector<int> v4 = v2;
    maxProductPairVer1(v4);

    vector<int> v5 {-20, 3, 5, -45, -5, 12, 56,9,-70, 70};
    maxProductPairVer1(v5);

    return a.exec();
}
