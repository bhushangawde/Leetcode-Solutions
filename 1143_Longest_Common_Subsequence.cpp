// O(n) space Bottom-Up DP
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        
        vector<int> curr(size2+1, 0);
        vector<int> prev(size2+1, 0);
        
        for(int j = 0; j <= size2; j++)
            prev[j] = 0;

        for(int i = 1; i <= size1; i++){
            curr[0] = 0;
            for(int j = 1; j <= size2; j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        
        return prev[size2];
    }
};

// O(n2) space Bottom-Up DP
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        
        int dp[size1+1][size2+1];
        
        for(int i = 0; i <= size1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j <= size2; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[size1][size2];
    }
};


// Plain recursive
class Solution {
public:
    int solve(string text1, string text2, int sz1, int sz2){
        if(sz1 == 0 || sz2 == 0)
            return 0;
        
        if(text1[sz1 - 1] == text2[sz2 - 1])
            return 1 + solve(text1, text2, sz1 - 1 ,sz2 - 1);
        
        return max(solve(text1, text2, sz1, sz2 - 1), solve(text1, text2, sz1 - 1 ,sz2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        
        return solve(text1, text2, size1, size2);
    }
};