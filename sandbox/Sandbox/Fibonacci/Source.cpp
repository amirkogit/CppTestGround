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
long FiboWithoutRecursion(long n)
{
    long low = 1;
    long high = 1;

    for (long i = 0; i < n; i++) {
        auto oldhigh = high;
        high = low + high;
        low = oldhigh;
    }

    return low;
}

// calculate the nth fibonacci number
// Complexity:
static long fiboCache[200];

long FiboWithDP(long n)
{
    if (n <= 1) {
        fiboCache[n] = 1;
    }
    if (fiboCache[n] == 0) {
        fiboCache[n] = FiboWithDP(n - 1) + FiboWithDP(n - 2);
    }
    return fiboCache[n];
}

int main()
{
    cout << "Fibonacci series demo..." << endl;

    int num = 100;

    cout << "Result (With recursion): " << FiboWithRecursion(num) << endl;
    cout << "Result (Without recursion): " << FiboWithoutRecursion(num) << endl;
    cout << "Result (With DP): " << FiboWithDP(num) << endl;

    getchar();
    return 0;
}