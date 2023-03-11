

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

