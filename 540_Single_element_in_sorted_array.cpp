class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int l = 0;
        int size = arr.size();
        int r = size - 1;
        int mid;
        
        if(size == 1 || arr[0] != arr[1])
            return arr[0];
        
        if(arr[size-1] != arr[size-2])
            return arr[size-1];
        
        while(l<=r){
            mid = (l + r)/2;
            
            if((arr[mid] != arr[mid + 1]) && (arr[mid] != arr[mid - 1]))
                return arr[mid];
            
            else if((arr[mid] == arr[mid + 1] && mid%2 == 0)|| (arr[mid] == arr[mid - 1] && mid%2 == 1)){
                l = mid + 1;
            }               
            else{
                r = mid - 1;
            }
        }
        
        return -1;
    }
};