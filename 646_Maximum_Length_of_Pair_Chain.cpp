// Using LIS
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int size = pairs.size();
        vector<int> dp(size, 1);
        for(int i = 1; i < size; i++){
            for(int j = 0; j < i; j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};