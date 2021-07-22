class Solution {
public:
    int dp[201][201] = {0};

    int longestPathUtil(vector<vector<int>>& matrix, int m, int n, int row, int col, int prev){
        
        if(row >= m || row < 0 || col >= n || col < 0)
            return 0;
        
        if(matrix[row][col] > prev){
            if (dp[row][col] > 0)
                return dp[row][col];
            int l,r,u,d;
            d = longestPathUtil(matrix, m, n, row + 1, col, matrix[row][col]);
            u = longestPathUtil(matrix, m, n, row - 1, col, matrix[row][col]);
            r = longestPathUtil(matrix, m, n, row, col+1, matrix[row][col]);
            l = longestPathUtil(matrix, m, n, row, col-1, matrix[row][col]);
            dp[row][col] = max(max(l,r), max(u,d)) + 1;
            return dp[row][col];
        }
        return 0;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxSize = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0; i < rows; i++){
            for(int j =0; j< cols; j++){
                maxSize = max(maxSize, longestPathUtil(matrix, rows,cols, i, j, -1));
                // cout<<maxSize<<endl;
            }
        }
        
        return maxSize;
    }
};