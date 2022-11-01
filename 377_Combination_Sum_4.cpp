// Recursion
class Solution {
public:

    int solveRec(vector<int>& nums, int target){
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;

        long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += solveRec(nums, target - nums[i]);
        }

        return ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return solveRec(nums, target);
    }
};


// Memoization
class Solution {
public:

    int solveMemo(vector<int>& nums, int target, vector<int>&dp){
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;

        if(dp[target] != -1)
            return dp[target];

        long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += solveMemo(nums, target - nums[i], dp);
        }
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solveMemo(nums, target, dp);
    }
};

