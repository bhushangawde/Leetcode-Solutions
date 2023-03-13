// Recursion + Memoization (Using string based map)
class Solution {
    unordered_map<string, bool> dp;
public:
    bool solve(string s1, string s2){
        if(s1.compare(s2) == 0){
            return true;
        } 
        string key = s1 + "$" + s2;
        if(dp.find(key) != dp.end())
            return dp[key];

        int n = s1.size();
        for(int i = 1; i <= n - 1; i++){
            bool cond1 = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i));
            bool cond2 = solve(s1.substr(0, i), s2.substr(n-i, i)) && solve(s1.substr(i, n-i), s2.substr(0, n-i));

            if(cond1 || cond2)
                return true;
        }
        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        if(s1.size() == 0 && s2.size() == 0)
            return true;
        return solve(s1,s2);
    }
};


// Recursion - TLE
class Solution {
public:
    bool solve(string s1, string s2){
        if(s1.compare(s2) == 0){
            return true;
        } 
        int n = s1.size();
        for(int i = 1; i <= n - 1; i++){
            bool cond1 = solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, n-i), s2.substr(i, n-i));
            bool cond2 = solve(s1.substr(0, i), s2.substr(n-i, i)) && solve(s1.substr(i, n-i), s2.substr(0, n-i));

            if(cond1 || cond2)
                return true;
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        if(s1.size() == 0 && s2.size() == 0)
            return true;
        return solve(s1,s2);
    }
};