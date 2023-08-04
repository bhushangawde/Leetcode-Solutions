// Simplied solution
class TicTacToe {
public:
    unordered_map<int, int> rowMp, colMp;
    int diag, revDiag;
    int num;
    TicTacToe(int n) {
        num = n;
        diag = 0;
        revDiag = 0;
    }
    
    int move(int row, int col, int player) {
        int currPlayer = (player == 1) ? 1 : -1;

        rowMp[row] += currPlayer;
        colMp[col] += currPlayer;
        if(row == col){
            diag += currPlayer;
        }
        if(row + col == num - 1){
            revDiag += currPlayer;
        }
        
        if(abs(diag) == num || abs(revDiag) == num || abs(rowMp[row]) == num || abs(colMp[col]) == num){
            return player;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

// First solution
class TicTacToe {
public:
    unordered_map<int, int> rowMp, colMp;
    int diag, revDiag;
    int num;
    TicTacToe(int n) {
        num = n;
        for(int i = 0; i < num; i++){
            rowMp[i] = 0;
            colMp[i] = 0;
        }
        diag = 0;
        revDiag = 0;
    }
    
    int move(int row, int col, int player) {
        
        if(player == 1){
            rowMp[row]--;
            colMp[col]--;
            if(row == col){
               diag--;
            }

            if(abs(row + col) == num - 1){
               revDiag--;
            }
        }
        else {
            rowMp[row]++;
            colMp[col]++;
            if(row == col){
                diag++;
            }
            if(abs(row + col) == num - 1){
               revDiag++;
            }
        }
        if(diag == -num || diag == num || revDiag == num || revDiag == -num)
            return player;

        if(rowMp[row] == -num || colMp[col] == -num || rowMp[row] == num || colMp[col] == num){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */