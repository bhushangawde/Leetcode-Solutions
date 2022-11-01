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

