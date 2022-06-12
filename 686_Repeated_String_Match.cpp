class Solution {
public:
    
	// KMP solution
    void buildLPS(int lps[], string pat){
        int i = 1;
        int len = 0;
        lps[0] = 0;
        int patLen = pat.size();
        while(i < patLen){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    int repeatedStringMatch(string a, string b) {
        int patLen = b.size();
        int num = 1;
        string c = a;
        int lps[patLen];
        buildLPS(lps, b);
        int ctr = 0;
        
        while(c.size() <= 2*b.size() || ctr < 2){
            if(c.size() < b.size()){
                c += a;
                num++;
                continue;
            }
                
            int i = 0;
            int j = 0;
            while(i < c.size()){
                if(c[i] == b[j]){
                    i++;
                    j++;
                }   
                if(j == patLen){
                    return num;
                }
                else if(i < c.size() && c[i] != b[j]){
                    if(j != 0)
                        j = lps[j - 1];
                    else
                        i++;
                }
            }
            num++;
            c += a;
            ctr++;
        }
        return -1;
    }
};