

// Top Down DP - Memoization - (0,0) -> (m,n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        return dfs(dp, 0, 0);
    }
    int dfs(vector<vector<int>>& dp, int i, int j) {
        if(i >= size(dp)   || j >= size(dp[0]))   return 0;  
        if(i == size(dp)-1 && j == size(dp[0])-1) return 1;    
        if(dp[i][j]) return dp[i][j];                           
        return dp[i][j] = dfs(dp, i+1, j) + dfs(dp, i, j+1);    
    }
};


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