class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        int i = 0;
        int j = 0;
        string ans = "";
        while(i < size1 || j < size2){
            if(i < size1)
                ans.push_back(word1[i++]);
            
            if(j < size2)
                ans.push_back(word2[j++]);
        }
        return ans;
    }
};