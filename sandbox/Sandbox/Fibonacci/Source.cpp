#include <iostream>

using namespace std;

// calculate the nth fibonacci number
// Complexity: Big-Theta(2^n)
int FiboWithRecursion(int n)
{
    if (n <= 1) {
        return 1;
    }
    return FiboWithRecursion(n - 1) + FiboWithRecursion(n - 2);

}

// calculate the nth fibonacci number
// Complexity: Big-Theta (2n)
int FiboWithoutRecursion(int n)
{
    int low = 1;
    int high = 1;

    for (int i = 0; i < n; i++) {
        auto oldhigh = high;
        high = low + high;
        low = oldhigh;
    }

    return low;
}

// calculate the nth fibonacci number
// Complexity:
void FiboWithDP(int num)
{

}

int main()
{
    cout << "Fibonacci series demo..." << endl;

    int num = 8;

    cout << "Result (With recursion): " << FiboWithRecursion(num) << endl;
    cout << "Result (Without recursion): " << FiboWithoutRecursion(num) << endl;


    getchar();
    return 0;
}