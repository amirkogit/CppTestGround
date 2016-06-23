#include "hacker_rank_challenges.h"

// standard library header includes
#include <iostream>
#include <cstdio>
#include <map>

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
// entry point for running hacker rank challeges problems
void HackerRankChallenges::RunAllDemos()
{
    std::cout << "Running all hacker rank challenges demo" << endl;
    
    //IntroHelloWorld();

    IntroForLoop();

    getchar();
}

//////////////////////////////////////////////////////////////////////////////////////
