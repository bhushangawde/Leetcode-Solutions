class Solution {
public:
    
	// O(log(mn)) solution
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0;
        int high = (n * m) - 1;
        
        while(low <= high){
            int mid = low + ((high - low) / 2);
            int curr = matrix[mid / m][mid % m];
            if(curr == target)
                return true;
            else if(curr > target) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return false;
    }
	
	// O(logm + n) solution
    bool binarySearch(vector<int> &row, int target){
        int low = 0;
        int high = row.size() - 1;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(row[mid] == target)
                return true;
            else if(row[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(target < matrix[0][0])
            return false;
        int row = 0;
        for(row = 0; row < matrix.size(); row++){
            if(matrix[row][0] > target)
                break;
        }
        return binarySearch(matrix[row-1], target);
    }
};