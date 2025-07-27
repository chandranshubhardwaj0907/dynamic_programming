//  Minimum Cost Tree From Leaf Values

class Solution {
public:
    // int recursion(vector<int>& arr, map<pair<int, int>, int>& maxi, int left,
    //               int right) {
    //     if (left == right) {
    //         return 0;
    //     }
    //     int ans = INT_MAX;

    //     for (int i = left; i < right; i++) {
    //         int leftCost = recursion(arr, maxi, left, i);
    //         int rightCost = recursion(arr, maxi, i + 1, right);
    //         int rootCost = maxi[{left, i}] * maxi[{i + 1, right}];
    //         ans = min(ans, leftCost + rightCost + rootCost);
    //     }

    //     return ans;
    // }

    int memo(vector<int>& arr, map<pair<int, int>, int>& maxi, int left,
             int right ,vector<vector<int >> &dp) {
        if (left == right) {
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int ans = INT_MAX;

        for (int i = left; i < right; i++) {
            int leftCost = memo(arr, maxi, left, i , dp);
            int rightCost = memo(arr, maxi, i + 1, right , dp);
            int rootCost = maxi[{left, i}] * maxi[{i + 1, right}];
            ans = min(ans, leftCost + rightCost + rootCost);
        }

        dp[left][right] = ans;
        return dp[left][right];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
            }
        }

        // int ans = recursion(arr, maxi, 0, n - 1);
        vector<vector<int >> dp(n+1 , vector<int>(n+1,-1));
        int ans = memo(arr,maxi  , 0 , n-1,dp);
        return ans;
    }
};