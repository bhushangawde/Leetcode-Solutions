// LCS Bottom up dp
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int s1ascii = 0;
        int s2ascii = 0;

        for(int i = 0 ; i < size1; i++){
            s1ascii += s1[i];
        }
        for(int i = 0 ; i < size2; i++){
            s2ascii += s2[i];
        }

        return s1ascii + s2ascii - 2 * dp[size1][size2];
    }
};