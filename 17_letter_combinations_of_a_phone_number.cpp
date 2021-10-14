class Solution {
public:
    unordered_map<int, vector<char>> mp;
    vector<string> ans;
    
    void solve(string digits, string& curr, int pos){
        if(pos == digits.size()){
            ans.push_back(curr);
            return;
        }
        int num = digits[pos] - '0';
        int size = mp[num].size();
        for(int i = 0 ; i < size; i++){
            curr.push_back(mp[num][i]);
            solve(digits, curr, pos+1);
            curr.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return ans;
        }
        
        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};
        
        string curr = "";
        solve(digits, curr, 0);
        return ans;
    }
};