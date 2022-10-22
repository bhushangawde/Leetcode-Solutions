class Solution {
public:
    
    void solve(vector<vector<int>> &ans, vector<int> &nums, int n){
        if(n == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = 0 ; i <= n ; i++){
            swap(nums[i], nums[n]);
            solve(ans,nums,n+1);
            swap(nums[i], nums[n]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(ans, nums, 0);
        return ans;
    }
};
