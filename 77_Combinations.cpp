//Backtracking
class Solution {
public:
    void solve(int n, int idx, int k, vector<vector<int>> &ans, vector<int> &vec){
        if(vec.size() == k){
            ans.push_back(vec);
            return;
        }
        for(int i = idx; i <= n; i++){
            vec.push_back(i);
            solve(n, i + 1, k, ans, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(n, 1, k, ans, vec);
        return ans;
    }
};