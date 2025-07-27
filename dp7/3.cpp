// edit distance


class Solution {
public:
    // int recursion(const string& word1, const string& word2, int i, int j) {

    //     if (i == word1.length()) {

    //         return word2.length() - j;
    //     }
    //     if (j == word2.length()) {

    //         return word1.length() - i;
    //     }

    //     if (word1[i] == word2[j]) {

    //         return recursion(word1, word2, i + 1, j + 1);
    //     } else {

    //         int insertOp = 1 + recursion(word1, word2, i, j + 1);

    //         int deleteOp = 1 + recursion(word1, word2, i + 1, j);

    //         int replaceOp = 1 + recursion(word1, word2, i + 1, j + 1);

    //         return min(insertOp, min(deleteOp, replaceOp));
    //     }
    // }

 int memo(const string& word1, const string& word2, int i, int j, vector<vector<int>> &dp) {
    if (i == word1.length()) {
        return word2.length() - j;
    }
    if (j == word2.length()) {
        return word1.length() - i;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (word1[i] == word2[j]) {
        dp[i][j] = memo(word1, word2, i + 1, j + 1, dp);
    } else {
        int insertOp = 1 + memo(word1, word2, i, j + 1, dp);
        int deleteOp = 1 + memo(word1, word2, i + 1, j, dp);
        int replaceOp = 1 + memo(word1, word2, i + 1, j + 1, dp);
        dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
    }
    return dp[i][j];
}


    int minDistance(string word1, string word2) {
        // return recursion(word1, word2, 0, 0);
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));

        int ans = memo(word1, word2, 0, 0, dp);
        return ans;
    }
};
