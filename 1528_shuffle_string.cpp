class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < s.length(); i++) {
            while (i != indices[i]) {
                int index = indices[i];
                swap(s[i], s[index]);
                swap(indices[i], indices[index]);
            }
        }
        
        return s;
    }
};