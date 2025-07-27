#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// ✅ Recursive solution (brute-force)
// Time Complexity: Exponential
int recursive(vector<int> &coins, int target)
{
    // Base case: exact change made
    if (target == 0)
        return 0;

    // Base case: invalid path (no solution)
    if (target < 0)
        return INT_MAX;

    int mini = INT_MAX;

    // Try every coin
    for (int i = 0; i < coins.size(); i++)
    {
        // Recursive call for (target - coin[i])
        int ans = recursive(coins, target - coins[i]);

        // If solution exists, update minimum
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1); // +1 for current coin
        }
    }

    return mini;
}

// ✅ Top-down DP (Memoization)
// Reduces time by storing solutions to subproblems
int coinchange(vector<int> &coins, int target, vector<int> &dp)
{
    // Base case: no more value to make
    if (target == 0)
        return 0;

    // Base case: invalid
    if (target < 0)
        return INT_MAX;

    // If already computed
    if (dp[target] != -1)
        return dp[target];

    int mini = INT_MAX;

    // Try every coin
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = coinchange(coins, target - coins[i], dp);

        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }

    // Save result in dp
    dp[target] = mini;
    return dp[target];
}
int solvetab(vector<int> &coins, int target)
{
    // Create a dp array of size (target + 1), initialized to INT_MAX
    vector<int> dp(target + 1, INT_MAX);

    // Base case: 0 coins needed to make amount 0
    dp[0] = 0;

    // Build the dp table iteratively
    for (int amount = 1; amount <= target; amount++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (amount - coins[j] >= 0 && dp[amount - coins[j]] != INT_MAX)
            {
                dp[amount] = min(dp[amount], dp[amount - coins[j]] + 1);
            }
        }
    }

    return (dp[target] == INT_MAX) ? -1 : dp[target]; // return -1 if not possible
}

// 🚀 Main function to test both methods
int main()
{
    vector<int> coins = {1, 2, 5}; // Available coin denominations
    int target = 7;                // Amount to form

    vector<int> dp(target + 1, -1); // Memoization array

    int ans_recursive = recursive(coins, target); // Without memoization
    int ans_memo = coinchange(coins, target, dp); // With memoization

    int ans = solvetab(coins, target);
    cout << "Tabulation answer: " << ans << endl;
    cout << "Recursive answer: " << ans_recursive << endl;
    cout << "Memoization answer: " << ans_memo << endl;

    return 0;
}
