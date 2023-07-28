// Simple to understand solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size == 1 || nums[0] != nums[1])
            return nums[0];

        if(nums[size - 1] != nums[size - 2])
            return nums[size - 1];

        int start = 0;
        int end = size - 1;

        while(start <= end){
            int mid = (start + end) / 2;

            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if(mid % 2 == 0){
                if(nums[mid] == nums[mid + 1]){
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            else {
                if(nums[mid - 1] == nums[mid]){
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};


// Solution 1
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