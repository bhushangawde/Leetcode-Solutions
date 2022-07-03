class Solution {
public:
    
    void reverseRow(vector<int> &matrixRow){
        int low = 0;
        int high = matrixRow.size() - 1;
        while(low < high){
            int temp = matrixRow[low];
            matrixRow[low] = matrixRow[high];
            matrixRow[high] = temp;
            low++;
            high--;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        for(int i = 0; i < n; i++){
            reverseRow(matrix[i]);
        }
    }
};