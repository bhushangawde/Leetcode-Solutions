class Solution {
public:


	// KMP algorithm
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
    
    int strStr(string haystack, string needle) {
        int needleLen = needle.size();
        int haystackLen = haystack.size();
        
        int lps[needleLen];
        computeLPS(needle, lps);
        
        int i = 0;
        int j = 0;
        while(i < haystackLen){
            if(needle[j] == haystack[i]){
                i++;
                j++;
            }
            
            if(j == needleLen){
                return i - j;
            }
            else if(i < haystackLen && needle[j] != haystack[i]){
                if(j != 0){
                    j = lps[j - 1];
                }
                else {
                    i++;
                }
            }
        }
        return -1;
    }
	
    /* int strStr(string haystack, string needle) {
        return haystack.find(needle);
    } */
};