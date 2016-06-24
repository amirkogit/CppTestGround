#include "hacker_rank_challenges.h"

// standard library header includes
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>

using namespace std;

HackerRankChallenges::HackerRankChallenges()
{
}


HackerRankChallenges::~HackerRankChallenges()
{
}

//////////////////////////////////////////////////////////////////////////////////////
// Format for defining methods for each coding challenges
// Method name: Title of the problem statement
//              For example, if the problem statement title is "For Loop" in the subdomain Introduction,
//              method name will be IntroForLoop()
// To test call these methods from the method "RunAllDemos()"
//
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
void IntroHelloWorld()
{
    std::cout << "Hello World";
}
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////

void IntroForLoop()
{
    // You will be given two positive integers, a and b (), separated by a newline.
    int a, b;
    cin >> a;
    cin >> b;

    map<int, string> digit_word_map;
    digit_word_map.insert(pair<int, string>(1, "one"));
    digit_word_map.insert(pair<int, string>(2, "two"));
    digit_word_map.insert(pair<int, string>(3, "three"));
    digit_word_map.insert(pair<int, string>(4, "four"));
    digit_word_map.insert(pair<int, string>(5, "five"));
    digit_word_map.insert(pair<int, string>(6, "six"));
    digit_word_map.insert(pair<int, string>(7, "seven"));
    digit_word_map.insert(pair<int, string>(8, "eight"));
    digit_word_map.insert(pair<int, string>(9, "nine"));

    for (int i = a; i <= b; i++) {
        // for all the integers in the range [a,b],print the english representation of it
        if (i >= 1 && i <= 9) {
            // print the english representation of it
            auto result = digit_word_map.find(i);
            string s = result->second;
            cout << s.c_str() << endl;
        }
        else {
            // if the number is even, print even otherwise print odd
            if (i % 2 == 0) {
                cout << "even\n";
            }
            else {
                cout << "odd\n";
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// Day 1: data types
void Day1DataTypes()
{
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    int i2;
    double d2 = 0.0;
    string s2;

    // Read and save an integer, double, and String to your variables.
    cin >> i2;
    cin >> d2;
    cin.ignore(); // ignore any newline character, can also use getchar()
    getline(cin, s2);

    // Print the sum of both integer variables on a new line.
    cout << i + i2 << endl;

    // Print the sum of the double variables on a new line.
    double result = (double)d + d2;
    cout.precision(1);
    cout << fixed <<result << endl; // here using std::fixed is necessary to correctly output 4.0 + 8.0 = 12.0, ot

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s + s2;

}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// Day2 operators
void Day2Operators()
{
    //There are  lines of numeric input :
    //The first line has a double, mealCost(the cost of the meal before tax and tip).
    //The second line has an integer, tipPercent (the percentage of  being added as tip).
    //The third line has an integer, taxPercent (the percentage of  being added as tax).

    // Output:
    //Print The total meal cost is totalCost dollars., where  is the rounded integer result of the entire bill(with added tax and tip).

    double mealCost{ 0.0 };
    int tipPercent{ 0 };
    int taxPercent{ 0 };

    cin >> mealCost;
    cin >> tipPercent;
    cin >> taxPercent;

    double tip = mealCost * ((double)tipPercent / 100);
    double tax = mealCost * ((double)taxPercent / 100);

    double totalCost = mealCost + tip + tax;
    //int totalCostRounded = (int)totalCost;

    cout << "The total meal cost is " << std::round(totalCost) << " dollars.";
}
//////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////
// entry point for running hacker rank challeges problems
void HackerRankChallenges::RunAllDemos()
{
    std::cout << "Running all hacker rank challenges demo" << endl;
    
    //IntroHelloWorld();

    //IntroForLoop();

    //Day1DataTypes();

    Day2Operators();

    getchar();
}

//////////////////////////////////////////////////////////////////////////////////////
