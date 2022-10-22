// Fast solution
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, int n){
        if(n == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        
        for(int i = n ; i < nums.size() ; i++){
            
            if(st.find(nums[i]) != st.end()){
                continue;
            }
            st.insert(nums[i]);
            
            swap(nums[i], nums[n]);
            solve(ans,nums,n+1);
            swap(nums[i], nums[n]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(ans, nums, 0);
        return ans;
    }
};



// Slight changes over permutation 1
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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(ans, nums, 0);
        set<vector<int>> st;
        for(auto it : ans)
            st.insert(it);
        
        vector<vector<int>> ans_2(st.begin(), st.end());
        
        return ans_2;
    }
};

