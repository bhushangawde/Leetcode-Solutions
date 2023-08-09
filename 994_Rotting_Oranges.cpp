// BFS

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int countFresh = 0;
        int countRotten = 0;
        for(int row = 0 ; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 2){
                    q.push({row, col});
                    countRotten++;
                }
                else if(grid[row][col] == 1)
                    countFresh++;
            }
        }
        if(countFresh == 0 && countRotten == 0)
            return 0;

        if(countRotten == 0)
            return -1;

        if(countFresh == 0)
            return 0;

        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int,int> elem = q.front();
                q.pop();
                int row = elem.first;
                int col = elem.second;
                if(row - 1 >= 0 && grid[row - 1][col] == 1){
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                }
                if(row + 1 < rows && grid[row + 1][col] == 1){
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                }
                if(col - 1 >= 0 && grid[row][col - 1] == 1){
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                }
                if(col + 1 < cols && grid[row][col + 1] == 1){
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                }
            }
            minutes++;
        }

        for(int row = 0 ; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    return -1;
                }
            }
        }
        return minutes - 1;
    }
};