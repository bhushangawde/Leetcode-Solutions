//Memoization + Decreasing function call stack
class Solution {
    int dp[2002][2002];
public:
    
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, int j){
        if(i >= j)
            return 0;
        if(isPalindrome(s, i, j))
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int mn = INT_MAX;
        for(int k = i; k <= j-1; k++){
            if(isPalindrome(s, i, k)){                         
                int temp = solve (s, k+1, j) + 1;
                mn = min(mn, temp);
            }
            // mn = min(mn, temp);
        }
        dp[i][j] = mn;
        return mn;
    }

    int minCut(string s) {
        if(s.size() == 1)
            return 0;
        memset(dp, -1, sizeof(dp));
        int ans = solve(s, 0, s.size() - 1);
        return ans;
    }
};

// Recurrsion TLE
class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string s, int i, int j){
        if(i >= j)
            return 0;
        if(isPalindrome(s, i, j))
            return 0;
        int mn = INT_MAX;
        for(int k = i; k <= j-1; k++){
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j);
            mn = min(mn, temp);
        }
        return mn;
    }

    int minCut(string s) {
        if(s.size() == 1)
            return 0;

        int ans = solve(s, 0, s.size() - 1);
        return ans;
    }
};

