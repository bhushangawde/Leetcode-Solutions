// Bottom-up DP

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        for(int i = 0 ; i < m; i++){
            if(obstacleGrid[i][0]){
                dp[i][0] = 0;
                break;
            }
            else 
                dp[i][0] = 1;
        }
        for(int i = 0 ; i < n; i++){
            if(obstacleGrid[0][i]){
                dp[0][i] = 0;
                break;
            }
            else
                dp[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j])
                    dp[i][j] = 0;
                else 
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

// Plain recursion
class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int rows, int cols, int r, int c){
        if(r < 0 || c < 0 || r >= rows || c >= cols)
            return 0;
        if(r == rows - 1 && c == cols - 1)
            return 1;
        if(obstacleGrid[r][c])
            return 0;
        return solve(obstacleGrid, rows, cols, r+1, c) + solve(obstacleGrid, rows, cols, r, c+1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        return solve(obstacleGrid, m, n, 0, 0);
    }
};