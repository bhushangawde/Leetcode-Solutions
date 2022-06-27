class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                cout<<"Condition 1" << endl;
                low++;
                high--;
                continue;
            }
            if(nums[mid] == nums[low]){
                cout<<"Condition 2" << endl;
                low = mid + 1;
            }
            else if(nums[mid] < nums[low]){
                cout<<"Condition 3" << endl;
                if(target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else if (nums[mid] > nums[low]){
                cout<<"Condition 4" << endl;
                if(target < nums[mid] && target >= nums[low])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};