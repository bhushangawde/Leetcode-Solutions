

// Recursion
class Solution {
public:
    bool solve(int idx, vector<int>& nums){
        if(idx == nums.size() - 1)
            return true;
        if(nums[idx] == 0)
            return false;

        for(int k = 1; k <= nums[idx]; k++){
            if(solve(idx + k, nums))
                return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(0, nums);
    }
};