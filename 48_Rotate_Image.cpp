class Solution {
public:
    
    void reverseRow(vector<int> &matrixRow){
        int low = 0;
        int high = matrixRow.size() - 1;
        while(low < high){
            swap(matrixRow[low], matrixRow[high]);
            low++;
            high--;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++){
            reverseRow(matrix[i]);
        }
    }
};