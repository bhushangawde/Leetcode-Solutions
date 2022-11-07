// Unordered map (Works for all unicode characters)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        int len = s.size();
        unordered_map<char, int> ump;
        for(int i = 0; i < len; i++){
            ump[s[i]]++;
            ump[t[i]]--;
        }

        for(auto elem : ump){
            if(elem.second != 0)
                return false;
        }
        return true; 
    }
};

// Sorting solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};