// Bottom-up DP
class Solution {
public:

    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)
            return true;
        vector<bool> dp(nums.size(), false);
        dp[size - 1] = true;
        for(int i = size - 2; i >= 0; i--){
            
            bool flag = false;
            for(int j = 1; j <= nums[i]; j++){
                if(i + j < size && dp[i + j]){
                    flag = true;
                    dp[i] = true;
                    break;
                }
            }
            if(flag)
                continue;
            
            dp[i] = false;
        }
        return dp[0];        
    }
};


// Greedy Approach
class Solution {
public:
    bool solveIter(vector<int>&nums){
        int n = nums.size();
        int last = n - 1;
        for(int i = n - 2; i >=0; i--){
            if(i + nums[i] >= last)
                last = i;
        }

        return last == 0;
    }
    bool canJump(vector<int>& nums) {
       return solveIter(nums);
    }
};

// Recursion + memoization
class Solution {
public:
    bool solve(int idx, vector<int>& nums, vector<int> &dp){
        if(idx == nums.size() - 1)
            return true;
        if(nums[idx] == 0)
            return dp[idx] = false;
        if(dp[idx] != -1)
            return dp[idx];

        for(int k = 1; k <= nums[idx]; k++){
            if(solve(idx + k, nums, dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

	bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
};

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