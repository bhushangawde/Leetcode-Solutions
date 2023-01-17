class Solution {
public:
    
//     int bstSearch(vector<int>arr, int l, int r, int target){
        
//         if(target < arr[l]){
//             return -1;
//         }
//         if(target > arr[r]){
//             return r;
//         }
//         while(l<=r){
//             int mid = l + (r-l)/2;
//             if(arr[mid] == target  || (arr[mid] < target && arr[mid + 1] > target))
//                 return mid;
//             if(target < arr[mid]){
//                 r = mid-1;
//             }
//             else{
//                 l = mid+1;
//             }
//         }
        
//         return -1;
//     }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currRow = 0;
        int currCol = matrix[0].size() - 1;
        
        while(currRow < matrix.size() && currCol > -1){
            if(matrix[currRow][currCol]  == target)
                return true;
            
            if(matrix[currRow][currCol] > target)
                currCol--;
            else
                currRow++;
        }
        
        return false;
    }
};