
// Plain Recursion
class Solution {
public:

    int solve(vector<int>& nums, int idx){
        if(idx >= nums.size())
            return 0;        
        return max(nums[idx] + solve(nums, idx + 2), solve(nums, idx + 1));
    }
    
    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};