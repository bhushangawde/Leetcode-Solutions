
// Iterative solution
class Solution {
public:
    
    int first(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int result = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                result = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return result;
    }
    
    int second(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int result = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                result = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return vector<int>{-1, -1};
        int firstOcc, secondOcc;
        firstOcc = first(nums, target);
        secondOcc = second(nums, target);
        // cout << firstOcc << endl;
        // cout << secondOcc << endl;
        vector<int> ans;
        ans.push_back(firstOcc);
        ans.push_back(secondOcc);
        return ans;
    }
};



// Recursive solution
class Solution {
public:
    
    int first(vector<int>& nums, int target, int l, int r){
        if(r >= l){
            int mid = l + (r-l)/2;
            
            if((nums[mid] == target && mid > 0 && nums[mid-1] != target) || (nums[mid] == target && mid == 0)){     
                return mid;
            }
            if(nums[mid] < target)
                return first(nums, target, mid+1, r);
            else
                return first(nums, target, l, mid-1);
        }
        return -1;
    }
    
    int last(vector<int>& nums, int target, int l, int r){
        if(r >= l){
            int mid = l + (r-l)/2;
            
            if((nums[mid] == target && mid < nums.size()-1 && nums[mid+1] != target) || (nums[mid] == target && mid == nums.size()-1)){     
                return mid;
            }
            if(nums[mid] > target)
                return last(nums, target, l, mid-1);
            else
                return last(nums, target, mid+1, r);
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int firstPos = first(nums, target, 0, nums.size()-1);
        int lastPos = last(nums, target, 0, nums.size()-1);
        // cout<<firstPos<<endl;
        ans.push_back(firstPos);
        ans.push_back(lastPos);
        
        return ans;
    }
};