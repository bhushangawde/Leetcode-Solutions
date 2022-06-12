class Solution {
public:
    
    void buildLPS(vector<int> &lps, string &pat){
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
    
    bool KMP(string &c, string &b, vector<int> &lps){
        int patLen = b.size();
        int i = 0;
        int j = 0;
        while(i < c.size()){
            if(c[i] == b[j]){
                i++;
                j++;
            }   
            if(j == patLen){
                return true;
            }
            else if(i < c.size() && c[i] != b[j]){
                if(j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }
    
    int repeatedStringMatch(string a, string b) {
        int patLen = b.size();
        int num = 1;
        string c = a;
        vector<int> lps(patLen, 0);
        buildLPS(lps, b);
        int ctr = 0;
        
        while(c.size() < b.size()){
            c += a;
            num++;
        }
        
        if(KMP(c, b, lps))
            return num;
        
        num++;
        c += a;
        
        if(KMP(c, b, lps))
            return num;
        return -1;
    }
};