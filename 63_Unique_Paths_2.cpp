
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