// Bottom up DP
class Solution {
public:
    int solve(int n, vector<int>& dp){
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        return solve(n, dp);    
    }
};


// Top down dp - Recursion + memoization
class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n <= 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += solve(i - 1, dp) * solve(n - i, dp);
        }
        return dp[n] = ans;
    }

    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);    
    }
};

// Recursive
class Solution {
public:

    int numTrees(int n) {
        if(n <= 1)
            return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += numTrees(i - 1) * numTrees(n - i);
        }
        return ans;
    }
};