
// From recursion tree
class Solution {
public:

    void solve(int n1, int n2, string s, vector<string> &ans){
        if(n1 == 0 && n2 == 0){
            ans.push_back(s);
            return;
        }
        
        if(n1 == n2 && n1 > 0){
            string s1 = s;
            s1.push_back('(');
            solve(n1-1, n2, s1, ans);
        }
        else if(n1 < n2){
            if(n1 > 0){
                string s1 = s;
                s1.push_back('(');
                solve(n1-1, n2, s1, ans);
                
                string s2 = s;
                s2.push_back(')');
                solve(n1, n2-1, s2, ans);
            }
            else if(n1 == 0){
                string s2 = s;
                s2.push_back(')');
                solve(n1, n2-1, s2, ans);
            }
        }
        
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(n, n, s, ans);
        return ans;    
    }
};