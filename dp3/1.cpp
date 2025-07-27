// fence problem


#include <iostream>
#include <vector>
using namespace std;

// 1. Recursive approach (Exponential time)
int recursion(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    return (recursion(n - 1, k) + recursion(n - 2, k)) * (k - 1);
}

// 2. Memoisation approach (Top-down DP)
int memoisation(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return k * k;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (memoisation(n - 1, k, dp) + memoisation(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

// 3. Tabulation approach (Bottom-up DP)
int solveUsingTab(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }

    return dp[n];
}

int main()
{
    int n = 4, k = 3;

    cout << "Using Recursion (n = 4, k = 3): " << recursion(n, k) << endl;

    n = 5;
    k = 3;

    vector<int> dp(n + 1, -1);
    cout << "Using Memoisation (n = 5, k = 4): " << memoisation(n, k, dp) << endl;

    cout << "Using Tabulation (n = 5, k = 4): " << solveUsingTab(n, k) << endl;

    return 0;
}
