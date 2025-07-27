#include <iostream>
#include <vector>
using namespace std;

// ✅ Recursive approach
int solveUsingRecursion(vector<int>& nums, int n) {
    if (n < 0) return 0;
    if (n == 0) return nums[0];

    int include = solveUsingRecursion(nums, n - 2) + nums[n];
    int exclude = solveUsingRecursion(nums, n - 1);

    return max(include, exclude);
}

// ✅ DP approach (top-down with memoization)
int solveUsingDP(vector<int>& nums, int n, vector<int>& dp) {
    if (n < 0) return 0;
    if (n == 0) return nums[0];

    if (dp[n] != -1) return dp[n];

    int include = solveUsingDP(nums, n - 2, dp) + nums[n];
    int exclude = solveUsingDP(nums, n - 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

// 🏠 House Robber wrapper using recursion
int robRecursive(vector<int>& nums) {
    int n = nums.size() - 1;
    return solveUsingRecursion(nums, n);
}

// 🏠 House Robber wrapper using DP
int robDP(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveUsingDP(nums, n - 1, dp);
}

// 🧪 Driver Code
int main() {
    vector<int> houses = {2, 7, 9, 3, 1};

    cout << "Max loot (Recursive): " << robRecursive(houses) << endl;
    cout << "Max loot (DP): " << robDP(houses) << endl;

    return 0;
}
