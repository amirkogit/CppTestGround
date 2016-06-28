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
#include <functional>
#include <cassert>

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


///////////////////////////////////////////////////////////
// Introduction/Arrays
void IntroArrays()
{
    int n; // size of array
    cin >> n;

    assert(!(n < 1 || n > 1000));

    vector<int> arr;
    arr.reserve(n);

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    // reverse the vector contents
    std::reverse(arr.begin(), arr.end());

    // print the contents
    for (auto elem : arr) {
        cout << elem << " ";
    }
}

///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Introduction/Preprocessor solution
// Sample solution
#define toStr(str) #str

#define io(data) cin >> data

#define foreach(arr, idx) \
for(int idx = 0; idx < arr.size(); idx++)

#define FUNCTION(name, op) \
void name(int &x, int y)\
{ \
    if(!(x op y)) \
        x = y;\
}

#define INF 1e9

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

void IntroPreprocessor()
{
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }

    int ans = mx - mn;
    cout << toStr(Result = ) << ' ' << ans;
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
// Day5 Loops
void Day5Loops()
{
    int n;
    cin >> n;

    if (n >= 2 && n <= 20) {
        for (int i = 1; i <= 10; i++) {
            cout << n << " x " << i << " = " << n*i << endl;
        }
    }

}
//////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
// Day 6 : review
void Day6LetsReview()
{
    int n; // total test cases
    cin >> n;
    cin.ignore();

    assert((n >= 1 && n <= 10));

    vector<string> input_strings;

    // read strings
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (s.length() >= 2 && s.length() <= 10000) {
            input_strings.push_back(s);
        }
    }

    // print the contents of input strings
#if 0
    cout << endl;
    for (auto elem : input_strings) {
        cout << elem << endl;
    }
#endif // 0

    for (auto elem : input_strings) {
        string s = elem;
        int idx = 0;
        vector<char> s_even;
        vector<char> s_odd;
        for (auto ch : s) {
            if (idx % 2 == 0 || idx == 0) {
                // even
                s_even.push_back(ch);
            }
            else {
                // odd
                s_odd.push_back(ch);
            }
            idx++;
        }

        // print even indexed characters
        for (auto e : s_even) {
            cout << e;
        }

        // print space
        cout << " ";

        // print odd indexed characters
        for (auto e : s_odd) {
            cout << e;
        }

        // newline
        cout << endl;
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
// Week of code 21 challenges
void WeekOfCode21Kangaroo()
{
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;

    // constraints check
    if (x1 < 0 || x1 > x2 || x1 > 10000 || x2 > 10000) {
        cout << "NO";
        return;
    }
    if (v1 < 1 || v1 > 10000) {
        cout << "NO";
        return;
    }
    if (v2 < 1 || v2 > 10000) {
        cout << "NO";
        return;
    }

    if (x2 > x1 && v2 > v1) {
        cout << "NO";
        return;
    }

    int trial = 0;
    bool found = false;
    for (trial = 0; trial <= 10000; trial++) {
        x1 += v1;
        x2 += v2;

        if (x1 == x2) {
            cout << "YES";
            found = true;
            break;
        }
    }

    if (found == false) {
        cout << "NO";
    }
}
//////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// Week of code 21 challenges - Luck balance
void WeekOfCode21LuckBalance()
{
    // N = number of preliminary contests
    // K = maximum number of important contests that Lena can lose
    // L = contest luck balance
    // T = contest important rating (0 or 1)
    int N, K, L, T;

    // constraints
    // 1 <= N <= 100
    // 0 <= K <= N
    // 1 <= L <= 10000
    // 0 <= T <= 1

    vector<int> imp_contests;
    vector<int> uimp_contests;

    // read contest numbers and max contest that can be lost
    cin >> N >> K;
    assert(!(N < 1 || N > 100));
    assert(!(K < 0 || K > N));

    for (int i = 0; i < N; i++) {
        int luck_balance = -1;
        cin >> luck_balance;
        assert(!(luck_balance < 1 || luck_balance > 10000));

        int contest_importance = -1;
        cin >> contest_importance;
        assert(!(contest_importance < 0 || contest_importance > 1));

        if (contest_importance == 1) {
            imp_contests.push_back(luck_balance);
        }
        else if (contest_importance == 0) {
            uimp_contests.push_back(luck_balance);
        }
    }

    // sort the contents of important contests
    std::sort(imp_contests.begin(), imp_contests.end(),std::greater<int>());

#if 0
    // print the contents of vector
    cout << "Contents of important contests: " << endl;
    for (auto elem : imp_contests) {
        cout << elem << endl;
    }

    cout << "Contents of unimportant contests: " << endl;
    for (auto elem : uimp_contests) {
        cout << elem << endl;
    }
#endif // 0

    // calculate the final luck balance by traversing through each elements
    int luck_tracker = 0;
    int final_luck_balance = 0;
    for (auto elem : imp_contests) {
        if (luck_tracker >= K) {
            final_luck_balance -= elem;
        }
        else {
            final_luck_balance += elem;
        }
        luck_tracker++;
    }

    for (auto elem : uimp_contests) {
        final_luck_balance += elem;
    }

    cout << final_luck_balance;
}
/////////////////////////////////////////////////////////


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

    //WorldCodeSprint4EqualStacks();

    //Day5Loops();

    //WeekOfCode21Kangaroo();

    //WeekOfCode21LuckBalance();

    //IntroArrays();

    //IntroPreprocessor();

    Day6LetsReview();

    getchar();
}

//////////////////////////////////////////////////////////////////////////////////////
