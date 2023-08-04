// Shorter solution
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto s : magazine)
            mp[s]++;
        
        for(auto s : ransomNote){
            mp[s]--;
            if(mp[s] == -1)
                return false;
        }
        return true;
    }
};

// Map
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto s : magazine)
            mp[s]++;
        
        for(auto s : ransomNote)
            mp[s]--;

        for(auto e : mp){
            if(e.second < 0)
                return false;
        }
        return true;
    }
};