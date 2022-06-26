class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int itr = len - 1;
        int ans = 0;
        while(s[itr] == ' '){
            itr--;
        }
        while(itr >= 0 && s[itr] != ' '){
            ans++;
            itr--;
        }
        return ans;
    }
};