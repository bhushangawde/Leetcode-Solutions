// Using Memoization
class Solution {
public:
    int solve(vector<int> &nums, int idx, vector<int>&dp, int n){
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1)
            return dp[idx];

        int rob = nums[idx] + solve(nums, idx + 2, dp, n);
        int dontRob = solve(nums, idx + 1, dp, n);

        return dp[idx] = max(rob, dontRob);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp1(nums.size(), -1);    
        vector<int> dp2(nums.size(), -1);    

        return max(solve(nums, 0, dp1, nums.size() - 1), solve(nums, 1, dp2, nums.size()));
    }
};