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
	
	
	// No KMP. Used substring approach.  https://leetcode.com/problems/repeated-substring-pattern/discuss/94346/29-ms-CPP-simple-solution.-No-KMP.
	
	/* bool repeatedSubstringPattern(string s) {
        int len = s.size();
        
        if(len == 1)
            return false;
        
        string first, second, s2;
        for(int i = 1; i <= len/2; i++){
            if(len % i == 0){
                first = s.substr(0, i);
                second = s.substr(i);
                s2 = second + first;
                
                if(s == s2)
                    return true;
            }
        }
        return false;
    } */
};