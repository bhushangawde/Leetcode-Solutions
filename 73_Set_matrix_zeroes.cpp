class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int colArr[cols];
        int rowArr[rows];
        
        for(int i = 0 ; i < rows; i++)
            rowArr[i] = 0 ;
        
        for(int j = 0 ; j < cols; j++)
            colArr[j] = 0 ;
        
        for(int i = 0 ; i < rows; i++){
            for(int j = 0 ; j < cols; j++){
                if(matrix[i][j] == 0){
                    rowArr[i] = 1;
                    colArr[j] = 1;
                }
            }
        }
        
        for(int i = 0 ; i < rows; i++){
            for(int j = 0 ; j < cols; j++){
                if(rowArr[i] == 1 || colArr[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};