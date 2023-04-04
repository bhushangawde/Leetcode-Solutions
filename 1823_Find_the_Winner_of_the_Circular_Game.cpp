

// O(n) extra space
class Solution {
public:

    void solve(int index, int k, vector<int> &vec, int &ans){
        if(vec.size() == 1){
            ans = vec[0];
            return;
        }
        
        index = (index + k) % (vec.size());
        vec.erase(vec.begin() + index);
        solve(index, k, vec, ans);
        return;
    }

    int findTheWinner(int n, int k) {
        vector<int> vec(n);
        for(int i = 0 ; i < n; i++)
            vec[i] = i+1;
        
        k = k-1;
        int ans;
        solve(0, k, vec, ans);
        return ans;
    }
};