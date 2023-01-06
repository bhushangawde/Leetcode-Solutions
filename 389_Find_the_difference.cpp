// XOR 
class Solution {
public:
    char findTheDifference(string s, string t) {
        int _xor = 0;
        for(auto e : s)
            _xor ^= e;
        
        for(auto e : t)
            _xor ^= e;
        
        return _xor;
    }
};