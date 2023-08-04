class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        int diag = 0;
        int antiDiag = 0;

        for(int i = 0; i < moves.size(); i++){
            int currPlayer = (i % 2) ? -1 : 1;
            int row = moves[i][0];
            int col = moves[i][1];

            rows[row] += currPlayer;
            cols[col] += currPlayer;

            if(row == col){
                diag += currPlayer;
            }
            if(row + col == 2){
                antiDiag += currPlayer;
            }

            if(rows[row] == 3 || cols[col] == 3 || diag == 3 || antiDiag == 3){
                return "A";
            }

            if(rows[row] == -3 || cols[col] == -3 || diag == -3 || antiDiag == -3){
                return "B";
            }
        }
        if(moves.size() < 9){
            return "Pending";
        }
        return "Draw";
    }
};