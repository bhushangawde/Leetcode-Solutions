class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int size = board.size();
        vector<int> rows(size, 0);
        vector<int> cols(size, 0);
        int diag = 0;
        int antiDiag = 0;
        int totalX = 0;
        int totalO = 0;

        for(int i = 0 ; i < size; i++){
            for(int j = 0 ; j < size; j++){
                if(board[i][j] != ' '){
                    int currPlayer = (board[i][j] == 'X') ? 1 : -1;
                    if(currPlayer == 1)
                        totalX++;
                    else
                        totalO++;

                    rows[i] += currPlayer;
                    cols[j] += currPlayer;
                    if(i == j){
                        diag += currPlayer;
                    }
                    if(i + j == size - 1){
                        antiDiag += currPlayer;
                    }
                }
            }
        }

        if(totalX - totalO > 1 || totalX - totalO < 0){
            return false;
        } 

        bool hasWonX = false;
        bool hasWonO = false;
        for(int i = 0 ; i < size; i++){
            if(rows[i] == size || cols[i] == size){
                if(hasWonO)
                    return false;
                hasWonX = true;
            }

            if(rows[i] == -size || cols[i] == -size){
                if(hasWonX)
                    return false;
                hasWonO = true;
            }
        }
        if(diag == size || antiDiag == size)
            hasWonX = true;

        if(diag == -size || antiDiag == -size)
            hasWonO = true;

        if(hasWonX == true && totalO == totalX){
            return false;
        }

        if(hasWonO == true && totalX > totalO){
            return false;
        }

        // if(abs(diag) == size || abs(antiDiag) == size){
        //     if(!hasWon)
        //         hasWon = true;
        //     else
        //         return false;
        // }
        return true;
    }
};