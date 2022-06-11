class Solution {
public:
    void computeLPS(string needle, int lps[]){
        int i = 1;
        int len = 0;
        lps[0] = 0;
        int needleLen = needle.size();
        while(i < needleLen){
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        int lps[len];
        
        computeLPS(s, lps);
        
        return lps[len - 1] && (lps[len - 1] % (len - lps[len - 1]) == 0);
    }
};