// O(1) extra space
class Solution {
public:

    int rob(vector<int>& nums) {
        int prev_prev = 0;
        int prev = nums[0];
        int curr;
        for(int i = 2; i <= nums.size(); i++){
            curr = max(nums[i-1] + prev_prev, prev);
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    }
};

// Bottom - Up DP
class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++){
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }
        return dp[nums.size()];
    }
};

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