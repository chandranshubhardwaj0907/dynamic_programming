// partition sum subset

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1️⃣ Pure Recursion (Exponential Time Complexity)
    bool solve(int index, vector<int>& nums, int target) {
        if (target == 0)
            return true;
        if (index >= nums.size() || target < 0)
            return false;

        // Include current element
        bool include = solve(index + 1, nums, target - nums[index]);

        // Exclude current element
        bool exclude = solve(index + 1, nums, target);

        return include || exclude;
    }

    // 2️⃣ Memoization (Top-Down DP)
    bool solve2(int index, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (index >= nums.size() || target < 0)
            return false;

        if (dp[index][target] != -1)
            return dp[index][target];

        // Include current element
        bool include = solve2(index + 1, nums, target - nums[index], dp);

        // Exclude current element
        bool exclude = solve2(index + 1, nums, target, dp);

        return dp[index][target] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // If total sum is odd, can't partition
        if (sum % 2 != 0) return false;

        int target = sum / 2;

        // Choose one of the following:

        // 1. Using pure recursion (⚠️ very slow for large inputs)
        // return solve(0, nums, target);

        // 2. Using memoization
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve2(0, nums, target, dp);
    }
};

// ✅ Main function
int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};  // You can test with different inputs

    if (sol.canPartition(nums)) {
        cout << "Can be partitioned into two equal subsets." << endl;
    } else {
        cout << "Cannot be partitioned into two equal subsets." << endl;
    }

    return 0;
}
