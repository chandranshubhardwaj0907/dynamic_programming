#include <iostream>
#include <vector>
using namespace std;

int recursion(int weight[], int value[], int index, int capacity)
{
    // Base case: only one item left to consider
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    // Case 1: Include current item (if possible)
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = recursion(weight, value, index - 1, capacity - weight[index]) + value[index];
    }

    // Case 2: Exclude current item
    int exclude = recursion(weight, value, index - 1, capacity);

    // Take maximum of including or excluding
    int ans = max(include, exclude);
    return ans;
}

int memoisation(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = memoisation(weight, value, index - 1, capacity - weight[index], dp) + value[index];
    }

    // Case 2: Exclude current item
    int exclude = memoisation(weight, value, index - 1, capacity, dp);

    // Take maximum of including or excluding
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};

    int n = 3;
    int capacity = 4;

    int ans = recursion(weight, value, n - 1, capacity);
    cout << "Maximum value in knapsack = " << ans << endl;

    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    int ans2 = memoisation(weight, value, n - 1, capacity, dp);
    cout << ans2;

    return 0;
}
