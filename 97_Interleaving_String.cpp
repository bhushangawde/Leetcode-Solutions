// Using Recursion
class Solution {
public:

    bool solve(string& s1, string& s2, string& s3, int l, int m, int n){
        if(n == -1 && m == -1 && l == -1){
            return true;
        }

        if(n == -1 && (m != -1 || l != -1)){
            return false;
        }

        if(m >= 0 && s3[n] == s2[m] && l >=0 && s3[n] == s1[l]){
            return solve(s1, s2, s3, l - 1, m, n - 1) || solve(s1, s2, s3, l, m - 1, n - 1);
        }
        
        if(m >= 0 && s3[n] == s2[m]){
            return solve(s1, s2, s3, l, m - 1, n - 1);
        }
        
        if(l >= 0 && s3[n] == s1[l]){
            return solve(s1, s2, s3, l - 1, m, n - 1);
        }

        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        return solve(s1, s2, s3, s1.size() - 1, s2.size() - 1, s3.size() - 1);
    }
};