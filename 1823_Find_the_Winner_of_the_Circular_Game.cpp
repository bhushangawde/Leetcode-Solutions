// Iterative O(1) extra space
class Solution {
public:

    int solve(int n, int k){
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = (ans + k) % i;
        return ans;
    }

    int findTheWinner(int n, int k) {
        return solve(n, k) + 1;
    }
};

// Recursive with auxilliary stack only
class Solution {
public:

    int solve(int n, int k){
        if(n == 1)
            return 0;
        return (solve(n-1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return solve(n, k) + 1;
    }
};

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