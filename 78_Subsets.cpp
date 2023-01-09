// Solution 1
class Solution {
public:
    vector<vector<int>> result;
    
    void powerset(vector<int> nums, int curr, vector<int> res, int n){
        result.push_back(res);
        for(int i = curr; i < n; i++){
            res.push_back(nums[i]);
            powerset(nums, i+1, res, n);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        powerset(nums, 0, res, n);
        return result;
    }
};


// Another solution
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

// Yet Another solution
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