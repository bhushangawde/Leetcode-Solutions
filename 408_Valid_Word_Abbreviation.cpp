class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int sw = word.size();
        int sa = abbr.size();
        int i = 0, j = 0;
        int num = 0;
        while(i < sw && j < sa){
            if(isdigit(abbr[j])){
                int num = 0;
                if(abbr[j] == '0') 
                    return false;
                while(j < sa && isdigit(abbr[j])){
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num;
            }
            else if(word[i] == abbr[j]){
                i++;
                j++;
            }
            else if(word[i] != abbr[j]){
                return false;
            }
        }
        if(i != sw || j != sa){
            return false;
        }
        return true;
    }
};