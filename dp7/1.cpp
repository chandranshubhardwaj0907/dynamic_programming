// longest increasing subsequence

class Solution {
public:
    //  int recursion(const vector<int>& nums, int curr, int prev) {
    //     if (curr == nums.size()) return 0;

    //     int take = 0;
    //     if (prev == -1 || nums[curr] > nums[prev])
    //         take = 1 + recursion(nums, curr+1, curr);

    //     int notTake = recursion(nums, curr+1, prev);

    //     return max(take, notTake);
    // }

   int memo(const vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
    if (curr == nums.size()) return 0;
    if (dp[curr][prev+1] != -1) return dp[curr][prev+1];

    int take = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        take = 1 + memo(nums, curr+1, curr, dp);
    int notTake = memo(nums, curr+1, prev, dp);

    return dp[curr][prev+1] = max(take, notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans = memo(nums,0,-1, dp);
        return ans;
    }
};