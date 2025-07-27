//  dynamic programming

// those who forget the past are condemned to repeat it

//  matlab jo ek baar calculate kr chuke ho use dubara calculaate nahi karna

//  3 approaches to solve this problem
// 1 top-down approach (memoization)
// 2 bottom-up approach (tabulation)
// 3 space optimized approach (tabulation)

// when to apply dynamic programming?
// 1. when the problem can be divided into subproblems
// 2. when the subproblems are overlapping

// fibonacci series
// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987

// f(5)
// f(4) + f(3)
// f(3)+ f(2)  + f(2) + f(1)
// f(1) + f(2)+ F(1) + f(0) + f(1)
// f(1) + F(1) + f(0) + f(0) + f(1)   BASE CASE
// 1  + 1 + 1 + 1 + 1 == 5

// we have seen that we calculate f(2) and f(1) multiple times so we can use DP
#include <iostream>
#include <vector>
using namespace std;

// Recursion
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

// Memoization
int fibmemo(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibmemo(n - 1, dp) + fibmemo(n - 2, dp);
    return dp[n];
}
// tabualation

int fibtabu(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// space optimisation
int spaceopt(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    int curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main()
{
    int n = 6;

    // Recursion result
    int ans = fib(n);

    // Memoization result
    vector<int> dp(n + 1, -1);
    int ans2 = fibmemo(n, dp);
    int ans3 = fibtabu(n, dp);
    int ans4 = spaceopt(n);
    cout << "Fibonacci using recursion: " << ans << endl;
    cout << "Fibonacci using memoization: " << ans2 << endl;
    cout << "Fibonacci using tabulation: " << ans3 << endl;
    cout << "Fibonacci using space optimisation: " << ans4 << endl;

    return 0;
}
