// four elements sum demo

//Given an array of integers, find all combination of four elements in the array whose sum is equal to a given value X.
//For example, if the given array is {10, 2, 3, 4, 5, 9, 7, 8} and X = 23,
//then your function should print “3 5 7 8” (3 + 5 + 7 + 8 = 23).

#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// brute force method
void findFourElementsVer0(int A[], int n, int X)
{
    cout << "X = " << X << endl;

    for(int i = 0; i < n-3; i++) {
        for(int j = i+1; j < n-2; j++) {
            for(int k = j+1; k < n-1; k++) {
                for(int l = k+1; l < n; l++) {
                    int sum = A[i] + A[j] + A[k] + A[l];
                    cout << A[i] << " + " << A[j] << " + " << A[k] << " + " << A[l] << " = " << sum << endl;
                    if(sum == X) {
                        cout << "Found result\n";
                        cout << A[i] << " + " << A[j] << " + " << A[k] << " + " << A[l] << " = " << sum << endl;
                    }
                }
            }
        }
    }
    cout << endl;
}

// brute force method: uses std::vector O(n^4)
void findFourElementsVer1(std::vector<int> input, int expectedSum)
{
    cout << "Expected sum = " << expectedSum << endl;
    int size = input.size();
    for(int i = 0; i < size-3; i++) {
        for(int j = i+1; j < size-2; j++) {
            for(int k = j+1; k < size-1; k++) {
                for(int l = k+1; l < size; l++) {
                    int sum = input[i] + input[j] + input[k] + input[l];
                    cout << input[i] << " + " << input[j] << " + " << input[k] << " + " << input[l] << " = " << sum << endl;
                    if(sum == expectedSum) {
                        cout << "Found result\n";
                        cout << input[i] << " + " << input[j] << " + " << input[k] << " + " << input[l] << " = " << sum << endl;
                    }
                }
            }
        }
    }
    cout << endl;
}

// sorting based method O(n^3)
void findFourElementsVer2(std::vector<int> input, int expectedSum)
{
    cout << "Expected sum = " << expectedSum << endl;
    int size = input.size();

    // sort the input
    std::vector<int> sortedInput = input;
    sort(begin(sortedInput), end(sortedInput));

    for(int i = 0; i < size - 3; i++) {
        for(int j = i + 1; j < size - 2; j++) {
            int left = j + 1;
            int right = size - 1;

            while(left < right) {
                int sum = input[i] + input[j] + input[left] + input[right];
                if(sum == expectedSum) {
                    cout << "Found result\n";
                    cout << input[i] << " + " << input[j] << " + " << input[left] << " + " << input[right] << " = " << sum << endl;
                    left++;
                    right--;
                }
                else if(sum < expectedSum) {
                    left++;
                }
                else {
                    right--;
                }
            } // end of while loop
        } // end of inner for loop
    } // end of outer for loop
}

// hash table based method O(n^2)
void findFourElementsVer3(std::vector<int> input, int expectedSum)
{
    // store sum of all pairs in a hash table
    unordered_map<int, pair<int,int>> mapPairs;
    for(int i = 0; i < input.size()-1; i++) {
        for(int j = 0; j < input.size(); j++) {
            mapPairs[input[i] + input[j]] = {i,j};
        }
    }

    // iterate through map to print all (key,value) pairs
    for(const auto& elem : mapPairs) {
        cout << "key: " << elem.first << " value (" << elem.second.first << "," << elem.second.second << ")" << endl;
    }

    // traverse through all pairs and search for
    // expectedSum - (current pair sum)
    for(int i = 0; i < input.size() - 1; i++) {
        for(int j = i + 1; j < input.size(); j++) {
            int sum = input[i] + input[j];

            if(mapPairs.find(expectedSum - sum) != mapPairs.end()) {
                // make sure that all elements are distinct array elements
                auto pair = mapPairs[expectedSum - sum];
                if(pair.first != i && pair.first != j && pair.second != i && pair.second != j) {
                    cout << "Found result\n";
                    cout << input[i] << " + " << input[j] << " + " << input[pair.first] << " + " << input[pair.second] << " = " << expectedSum << endl;
                    return;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Four elements sum\n";
    vector<int> input {10, 20, 30, 40, 1, 2};

#if 0
    cout << "O^4 solution:\n";
    findFourElementsVer1(input,91);

    cout << "O^3 solution:\n";
    findFourElementsVer2(input,91);
#endif

    cout << "O^2 solution:\n";
    findFourElementsVer3(input,91);

    return a.exec();
}
