class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int num = nums.size();
        int high = num - 1;
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            int next = (mid + 1) % num;
            int prev = (mid + num - 1) % num;
            
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
                return nums[mid];
            
            if(nums[mid] <= nums[high])
                high = mid - 1;
            else if(nums[mid] >= nums[low])
                low = mid + 1;
        }
        return -1;
    }
};