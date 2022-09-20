// Iterative
class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};


// Recursive
class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int curr){
        if(curr < 0){
            ans.push_back(temp);
            return;
        }    
        temp.push_back(nums[curr]);
        solve(ans,temp,nums,curr-1);
        temp.pop_back();
        solve(ans,temp,nums,curr-1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = nums.size();
        solve(ans, vec, nums, n-1);
        return ans;
    }
};