class Solution {
public:

	// O(1) space solution
	void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool isCol = false;
        bool isRow = false;
        
        for(int i = 0 ; i < rows; i++){
            if(matrix[i][0] == 0)
                isCol = true;
        }
        
        for(int j = 0 ; j < cols; j++){
            if(matrix[0][j] == 0)
                isRow = true;
        }
        
        for(int i = 1 ; i < rows; i++){
            for(int j = 1 ; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1 ; i < rows; i++){
            for(int j = 1 ; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(isCol){
            for(int i = 0 ; i < rows; i++){
                matrix[i][0] = 0;
            }
        }
        
        if(isRow){
            for(int j = 0 ; j < cols; j++){
                matrix[0][j] = 0;
            }
        }
    }
	

	// O(n+m) space solution	
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