// For lowercase english alphabets
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) 
			return false;
        int len = s.length();
        int counts[26] = {0};
        for (int i = 0; i < len; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i] != 0) 
				return false;
			
        return true;
    }
};

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