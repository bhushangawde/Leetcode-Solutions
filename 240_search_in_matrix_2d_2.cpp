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
        int n = matrix[0].size();
        int m = matrix.size();
        // int outp = bstSearch(matrix[0],0,4,target);
        int j = 0;
        int i = m-1;
        while(j<n && i>=0){
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] > target){
                i--;
            }
            else if(matrix[i][j] < target){
                j++;
            }
        }
        
        return false;
    }
};