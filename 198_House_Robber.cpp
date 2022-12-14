
// Recursion + memoization
class Solution {
public:

    int solve(vector<int>& nums, vector<int>& dp, int idx){
        if(idx >= nums.size())
            return 0;        
        if(dp[idx] != -1) 
            return dp[idx];
        dp[idx] = max(nums[idx] + solve(nums, dp, idx + 2), solve(nums, dp, idx + 1));
        return dp[idx];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, dp, 0);
        return dp[nums.size()-1];
    }
};

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