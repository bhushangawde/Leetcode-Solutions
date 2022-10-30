class Solution {
public:

    bool usedInRow(vector<vector<char>>& board, int row, int num){
        for(int i = 0 ; i < 9; i++){
            if(int(board[row][i] - '0') == num){
                return true;
            }
        }
        return false;
    }

    bool usedInCol(vector<vector<char>>& board, int col, int num){
        for(int i = 0 ; i < 9; i++){
            if(int(board[i][col] - '0') == num){
                return true;
            }
        }
        return false;
    }

    bool usedInBox(vector<vector<char>>& board, int row, int col, int num){
        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for(int i = 0 ; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(int(board[startRow + i][startCol + j] - '0') == num){
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, int num){
        if(!usedInBox(board, row, col, num) && !usedInCol(board, col, num) && !usedInRow(board, row, num)){
            return true;
        }
        return false;
    }

    bool solve(vector<vector<char>>& board, int row, int col){
        if(row == 8 && col == 9)
            return true;
        
        if(col == 9){
            col = 0;
            row++;
        }
        if(board[row][col] != '.')
            return solve(board, row ,col+1);
        
        for(int num = 1 ; num <= 9; num++){
            // cout<<isSafe(board, row, col, num)<<endl;
            if(isSafe(board, row, col, num) && board[row][col] == '.'){
                // cout<<row<< " "<<col<<endl;
                // cout<<char(num + 48)<<endl;
                board[row][col] = char(num + 48);
                if(solve(board, row, col+1))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};