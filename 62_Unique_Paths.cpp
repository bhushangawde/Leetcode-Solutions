

// Top Down DP - Memoization - (m,n) -> (0,0)
class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp){
        if (m == 0 || n == 0) {
            return 0;
        }
        if(m == 1 && n == 1)
            return 1;

        if(dp[m][n])
            return dp[m][n];
        return dp[m][n] = solve(m - 1, n, dp) + solve(m, n - 1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+2, vector<int>(n+2, 0));
        return solve(m,n,dp);
    }
};