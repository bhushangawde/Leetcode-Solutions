class Solution {
public:
    int search(vector<int>& arr, int target) {
        int f = 0;
        int l = arr.size() - 1;
        
        if(l == -1)
            return -1;
        
        while(f<=l){
            int mid = f + (l-f)/2;
            if(arr[mid] == target)
                return mid;
            
            if(arr[mid] >= arr[l]){
                if(target >= arr[f] && target <= arr[mid])
                    l = mid-1;
                else
                    f = mid+1;
            }
            else{
                if(target <= arr[l] && target >= arr[mid])
                    f = mid+1;
                else
                    l = mid-1;
            }
        }
        
        return -1;
    }
};