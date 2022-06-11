class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin = 0;
        int colBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        vector<int> ans;
        
        while(rowBegin <= rowEnd || colBegin <= colEnd){
            if(rowBegin <= rowEnd){
                for(int i = colBegin; i <= colEnd; i++){
                    ans.push_back(matrix[rowBegin][i]);
                }
            }
            rowBegin++;
            
            if(colBegin <= colEnd){
                for(int i = rowBegin; i <= rowEnd; i++){
                    ans.push_back(matrix[i][colEnd]);
                }
            }
            colEnd--;
            
            if(rowBegin <= rowEnd){
                for(int i = colEnd; i >= colBegin; i--){
                    ans.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd--;
            
            if(colBegin <= colEnd){
                for(int i = rowEnd; i >= rowBegin; i--){
                    ans.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++;
        }
        
        return ans;
    }
};