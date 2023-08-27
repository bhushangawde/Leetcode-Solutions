// Using BFS
class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dRow[8] = {0, 1, 1, 1, 0,-1, -1, -1};
        int dCol[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));        
        q.push({0, 0, 1});
        
        if(grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
            return -1;
        visited[0][0] = 1;
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            int row = curr[0];
            int col = curr[1];
            int steps = curr[2];
            
            if(row == m - 1 && col == n - 1){
                return steps;
            }

            for(int i = 0 ; i < 8; i++){
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if(newRow >= 0 && newRow < m && newCol >=0 && newCol < n && grid[newRow][newCol] == 0 && !visited[newRow][newCol]){
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol, steps + 1});
                }

            }
        }
        return -1;

    }
};