//  dp on string 
//  longest common subsequence


class Solution {
public:
    // int recursion(const string &text1, const string &text2 , int i , int j){
    //     if(i == text1.length()){
    // return 0;
    //     }
    //       if(j == text2.length()){
    // return 0;
    //     }

    //     int ans = 0;
    //     if(text1[i] == text2[j]){
    //         ans = 1 + recursion(text1 , text2 , i+1 , j+1);
    //     }
    //     else{
    //         ans = 0 + max(recursion(text1 , text2 , i+1 , j) ,
    //         recursion(text1 , text2 , i , j+1));
    //     }
    //     return ans;
    // }

 int memo(const string &text1, const string &text2 , int i , int j , vector<vector<int>> &dp) {
        if (i == text1.length() || j == text2.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + memo(text1, text2, i+1, j+1, dp);
        } else {
            dp[i][j] = max(memo(text1, text2, i+1, j, dp),
                           memo(text1, text2, i, j+1, dp));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        int ans = memo(text1, text2, i, j, dp);
        return ans;
    }
};

