// Bottom-Up DP - O(n) space
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, -1);
        vector<int> curr(n, -1);
        for(int i = 0 ; i < n; i++)
            prev[i] = 1;

        for(int i = 1; i < m; i++){
            curr[0] = 1;
            for(int j = 1; j < n; j++){
                curr[j] = curr[j-1] + prev[j];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

// Bottom-Up DP - O(n2) space
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long>> dp(m, vector<long>(n, -1));
        for(int i = 0 ; i < m; i++)
            dp[i][0] = 1;
        for(int i = 0 ; i < n; i++)
            dp[0][i] = 1;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

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