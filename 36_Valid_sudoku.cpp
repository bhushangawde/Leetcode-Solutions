

// Long and slower solution - O(n2) multiple loops
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> mp_row;
        unordered_map<char,int> mp_col;
        unordered_map<char,int> mp_box;  
        
        for(int i = 0; i < board.size(); i++){
            mp_row.clear();
            for(int j = 0; j < board[0].size(); j++){              
                if(board[i][j] != '.'){
                    if(mp_row[board[i][j]] == 1){
                        return false;
                    }
                    mp_row[board[i][j]] = 1;     
                }
            }
        }
        for(int i = 0; i < board[0].size(); i++){
            mp_col.clear();
            for(int j = 0; j < board.size(); j++){               
                if(board[j][i] != '.'){
                    if(mp_col[board[j][i]] == 1){
                        return false;
                    }
                    mp_col[board[j][i]] = 1;     
                }
            }
        }
        
        for(int i = 0; i < board.size(); i+=3){
            for(int j = 0; j < board[0].size(); j+=3){ 
                mp_box.clear();
                for(int startRow = i; startRow < i + 3; startRow++){
                    for(int startCol = j; startCol < j + 3; startCol++){
                        if(board[startRow][startCol] != '.'){
                            if(mp_box[board[startRow][startCol]] == 1){
                                return false;
                            }
                            mp_box[board[startRow][startCol]] = 1;     
                        }       
                    }
                }
            }
        }
        
        return true;
    }
};