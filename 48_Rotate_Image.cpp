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
	
	
	
	// Using Index manipulation - Difficult (Ring by Ring approach)
	/* void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n - 1;
        int diff = b - a;
        
        while(a < b){
            diff = b - a;
            for(int i = 0 ; i < diff; i++){
                int temp = matrix[a][a + i];
                matrix[a][a + i] = matrix[b - i][a];
                matrix[b - i][a] = matrix[b][b - i];
                matrix[b][b - i] = matrix[a + i][b];
                matrix[a + i][b] = temp;
            }               
            a++;
            b--;
        }
    } */
};