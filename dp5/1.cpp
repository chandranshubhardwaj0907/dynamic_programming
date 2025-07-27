// guess number problem


int solveusingmemo(int start, int end, vector<vector<int>>& dp) {
    if (start >= end) {
        return 0;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }

    int ans = INT_MAX;

    for (int i = start; i <= end; i++) {
        int cost = i + max(solveusingmemo(start, i - 1, dp),
                           solveusingmemo(i + 1, end, dp));
        ans = min(ans, cost);
    }

    dp[start][end] = ans;
    return ans;
}
