// counting elements in two arrays
//Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates.
// For each element in arr1[] count elements less than or equal to it in array arr2[].

//Input:
//The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integers m and n denoting the size of the two arrays. The following two lines will contain both the arrays respectively.

//Output:
//Print the count of elements less than or equal to it in arr2 for each element in arr1.

//Constraints:
//1<=T<=10^5
//1<=m,n<=10^5
//1<=arr1[i],arr2[j]<=10^5

//Example:
//Input:
//2
//6 6
//1 2 3 4 7 9
//0 1 2 1 1 4
//5 7
//4 8 7 5 1
//4 48 3 0 1 1 5

//Output:
//4 5 5 6 6 6
//5 6 6 6 3

#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <algorithm>>

using namespace std;

void printVector(const std::vector<int> vec)
{
    for(const auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}

int binarySearch(const std::vector<int>& vec, int elem)
{
    int leftHalf = 0;
    int rightHalf = vec.size() - 1;

    while(leftHalf <= rightHalf) {
        int mid = (leftHalf + rightHalf) / 2;
        if(vec[mid] <= elem) {
            leftHalf = mid + 1;
        }
        else {
            rightHalf = mid - 1;
        }
    }

    return rightHalf;
}

void countElementsLessThanOrEqualTo(std::vector<int>& arr1, std::vector<int>& arr2)
{
    // sort the 2nd array
    sort(begin(arr2), end(arr2));
    printVector(arr2);

    // for each element in the first array, get the last index of
    // element smaller than or equal to elem in the first array
    for(auto elem : arr1) {
        int index = binarySearch(arr2, elem);
        cout << (index + 1) << " ";
    }

    cout << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Counting elements in two arrays\n";

    // input set 1
    std::vector<int> arr1 {1, 2, 3, 4, 7, 9};
    std::vector<int> arr2 {0, 1, 2, 1, 1, 4};
    printVector(arr2);
    countElementsLessThanOrEqualTo(arr1, arr2);

    // input set 2
    std::vector<int> arr3 {4, 8, 7, 5, 1};
    std::vector<int> arr4 {4, 48, 3, 0, 1, 1, 5};
    printVector(arr4);
    countElementsLessThanOrEqualTo(arr3,arr4);

    return a.exec();
}

// Reference: geek4geek

/*

Naive Approach: Using two loops, outer loop for elements of array arr1[] and inner loop for elements of array arr2[].
Then for each element of arr1[], count elements less than or equal to it in arr2[].
Time complexity: O(m * n), considering arr1[] and arr2[] are of sizes m and n respectively.

Efficient Approach: Sort the elements of 2nd array, i.e., array arr2[].
Then perform a modified binary search on array arr2[]. For each element x of array arr1[],
find the last index of the largest element smaller than or equal to x in sorted array arr2[].


// C++ implementation of For each element in 1st
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>

using namespace std;

// function returns the index of largest element
// smaller than equal to 'x' in 'arr'. For duplicates
// it returns the last index of occurrence of required
// element. If no such element exits then it returns -1.
int binary_search(int arr[], int l, int h, int x)
{
    while (l <= h)
    {
        int mid = (l+h) / 2;

        // if 'x' is greater than or equal to arr[mid],
        // then search in arr[mid+1...h]
        if (arr[mid] <= x)
            l = mid + 1;

        // else search in arr[l...mid-1]
        else
            h = mid - 1;
    }

    // required index
    return h;
}

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
void countEleLessThanOrEqual(int arr1[], int arr2[],
                             int m, int n)
{
    // sort the 2nd array
    sort(arr2, arr2+n);

    // for each element of 1st array
    for (int i=0; i<m; i++)
    {
        // last index of largest element
        // smaller than or equal to x
        int index = binary_search(arr2, 0, n-1, arr1[i]);

        // required count for the element arr1[i]
        cout << (index+1) << " ";
    }
}

// Driver program to test above
int main()
{
    int arr1[] = {1, 2, 3, 4, 7, 9};
    int arr2[] = {0, 1, 2, 1, 1, 4};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    countEleLessThanOrEqual(arr1, arr2, m, n);
    return 0;
}
*/
