
// Not modifying input
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        ans[0] = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            ans[i] = nums[i] + ans[i-1];
        }
        return ans;
    }
};

// Modifies input
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int i = 1;
        while(i < nums.size()){
            nums[i] += nums[i-1];
            i++;
        }
        return nums;
    }
};