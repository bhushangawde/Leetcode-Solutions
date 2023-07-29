// Bottom up dp - O(1) space
class Solution {
public:
    int solve(vector<int> &nums, int idx, vector<int>&dp, int n){
        int prev_prev = 0;
        int prev = nums[idx];

        for(int i = idx + 1; i < n; i++){
            int curr = max(nums[i] + prev_prev, prev);
            prev_prev = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp1(nums.size() + 2, -1);    
        vector<int> dp2(nums.size() + 2, -1);    

        return max(solve(nums, 0, dp1, nums.size() - 1), solve(nums, 1, dp2, nums.size()));
    }
};


// Using bottom up - supports both arrays
class Solution {
public:
    int solve(vector<int> &nums, int idx, vector<int>&dp, int n){
        dp[0] = 0;
        dp[1] = nums[idx];

        int dpidx = 2;

        for(int i = idx + 1; i < n; i++){
            dp[dpidx] = max(dp[dpidx - 1], dp[dpidx - 2] + nums[i]);
            dpidx++;
        }

        return dp[dpidx - 1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        vector<int> dp1(nums.size() + 2, -1);    
        vector<int> dp2(nums.size() + 2, -1);    

        return max(solve(nums, 0, dp1, nums.size() - 1), solve(nums, 1, dp2, nums.size()));
    }
};

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