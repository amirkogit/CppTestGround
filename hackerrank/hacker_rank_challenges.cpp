#include "hacker_rank_challenges.h"

// standard library header includes
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>

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

// Introduction/Functions
// *****************************

//Add `int max_of_four(int a, int b, int c, int d)` here.
int max_of_four(int a, int b, int c, int d)
{
    vector<int> list = { a,b,c,d };
    auto max = std::max_element(list.begin(), list.end());
    return *max;
}

void IntroFunction()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    vector<int> list;
}

///////////////////////////////////////////////////////////

// Introduction/Pointer
void update(int *a, int *b) {
    // Complete this function    
    int tempa = *a;
    int tempb = *b;
    *a = tempa + tempb;
    *b = std::abs(tempa - tempb);
}

void IntroPointer()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}

///////////////////////////////////////////////////////////


// 30 days coding challenge
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
// Day 3 Intro to conditional statements
void Day3ConditionalStatements()
{
    int n;
    cin >> n;

    if (n % 2 != 0) {
        // number is odd
        cout << "Weird";
    }
    else {
        // number is even
        if (n >= 2 && n <= 5) {
            cout << "Not Weird";
        }
        else if (n >= 6 && n <= 20) {
            cout << "Weird";
        }
        else if (n > 20) {
            cout << "Not Weird";
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
// World CodeSprint#4 Minimum distance
void WorldCodeSprint4MinimumDistance()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    std::vector<int> results;

    // store each value in the map
    std::map<int, int> value_index_map;

    for (int i = 0; i < A.size(); ++i) {
        int index = i;
        int val = A.at(i);

        int abs_diff = 0;

        auto findval = value_index_map.find(val);
        if (findval != value_index_map.end()) {
            // get the previously stored index value
            int prev_idx = findval->second;

            // store the absolute difference
            abs_diff = std::abs(prev_idx - index);

            results.push_back(abs_diff);

            //value_index_map.insert(std::pair<int, int>(A.at(i), abs_diff));
        }
        else {
            // first time insert
            value_index_map.insert(std::pair<int, int>(A.at(i), index));
        }
    }

    sort(results.begin(), results.end(),std::less<int>());

    // sort the values of results
    //for (auto elem : results) {
    //    cout << elem;
    //}

    int min_distance = -1;
    if (results.size() > 0) {
        min_distance = results.at(0);
    }
    cout << min_distance;
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// World CodeSprint#4 Equal stacks

int GetStackHeight(std::stack<int> in_stack)
{
    int height{0};
    while (!in_stack.empty()) {
        height += in_stack.top();
        in_stack.pop();
    }
    return height;
}

void WorldCodeSprint4EqualStacks()
{
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    for (int h1_i = 0; h1_i < n1; h1_i++) {
        cin >> h1[h1_i];
    }
    vector<int> h2(n2);
    for (int h2_i = 0; h2_i < n2; h2_i++) {
        cin >> h2[h2_i];
    }
    vector<int> h3(n3);
    for (int h3_i = 0; h3_i < n3; h3_i++) {
        cin >> h3[h3_i];
    }

    // define three stacks
    std::stack<int> stack1;
    std::stack<int> stack2;
    std::stack<int> stack3;

    std::vector<std::pair<int,int>> stack_heights(3);

    // insert the input items into respective stacks
    for (auto iter = h1.rbegin(); iter != h1.rend(); ++iter) {
        stack1.push(*iter);
    }

    for (auto iter = h2.rbegin(); iter != h2.rend(); ++iter) {
        stack2.push(*iter);
    }

    for (auto iter = h3.rbegin(); iter != h3.rend(); ++iter) {
        stack3.push(*iter);
    }

    // check if the heights of all stacks are same
    bool all_same_height = false;
    int final_height = 0;
    while (!all_same_height){
        // 1. check the heights of all stacks
        // 2. if all heights are equal, break the loop
        // 3. if not, find the stack with the max height
        // 4. pop the element from that stack
        // 5. repeat from 1
        int ht1 = GetStackHeight(stack1);
        int ht2 = GetStackHeight(stack2);
        int ht3 = GetStackHeight(stack3);
        stack_heights.clear();
        stack_heights.push_back(std::make_pair(1, ht1));
        stack_heights.push_back(std::make_pair(2, ht2));
        stack_heights.push_back(std::make_pair(3, ht3));

        if ((ht1 == ht2) && (ht2 == ht3)) {
            all_same_height = true;
            final_height = ht1;
            break;
        }
        else {
            int max_height = std::max({ ht1,ht2,ht3 });

            // find which of the stack has the max height
            int stack_num = 0;
            for (auto elem : stack_heights) {
                if (elem.second == max_height) {
                    stack_num = elem.first;
                }
            }

            if (stack_num == 1) {
                stack1.pop();
            }
            else if (stack_num == 2) {
                stack2.pop();
            }
            else if (stack_num == 3) {
                stack3.pop();
            }
        }
    }

    cout << final_height;
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

    //Day2Operators();

    //Day3ConditionalStatements();

    //IntroFunction();

    //IntroPointer();

    //WorldCodeSprint4MinimumDistance();

    WorldCodeSprint4EqualStacks();

    getchar();
}

//////////////////////////////////////////////////////////////////////////////////////
