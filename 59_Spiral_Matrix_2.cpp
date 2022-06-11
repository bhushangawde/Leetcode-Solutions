class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int rowBegin = 0;
        int colBegin = 0;
        int rowEnd = n-1;
        int colEnd = n-1;
        int val = 1;
        while(rowBegin <= rowEnd || colBegin <= colEnd){
            if(rowBegin <= rowEnd){
                for(int i = colBegin; i <= colEnd; i++){
                    matrix[rowBegin][i] = val;
                    val++;
                }
            }
            rowBegin++;
            
            if(colBegin <= colEnd){
                for(int i = rowBegin; i <= rowEnd; i++){
                    matrix[i][colEnd] = val;
                    val++;
                }
            }
            colEnd--;
            
            if(rowBegin <= rowEnd){
                for(int i = colEnd; i >= colBegin; i--){
                    matrix[rowEnd][i] = val;
                    val++;
                }
            }
            rowEnd--;
           
            if(colBegin <= colEnd){
                for(int i = rowEnd; i >= rowBegin; i--){
                    matrix[i][colBegin] = val;
                    val++;
                }
            }
            colBegin++;
        }
        
        return matrix;
    }
};