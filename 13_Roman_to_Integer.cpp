class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        int ans = ump[s[s.size() - 1]];
        if(s.size() == 1){
            return ans;
        }
        for(int i=s.size() - 2; i>=0; i--){
            if(ump[s[i]] < ump[s[i+1]]){
                ans -= ump[s[i]];
            }
            else {
                ans += ump[s[i]];
            }
        }
        return ans;
    }
};