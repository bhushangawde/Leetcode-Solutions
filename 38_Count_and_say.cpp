class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 0 ; i < n-1 ; i++){
            string current = "";
            for(int j = 0 ; j < ans.size(); j++){
                int cnt = 1;
                while(j + 1 < ans.size() && ans[j] == ans[j + 1]){
                    cnt++;
                    j++;
                }
                current += to_string(cnt) + ans[j];
            }
            ans = current;
        }
        return ans;
    }
};