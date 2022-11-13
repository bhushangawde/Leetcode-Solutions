// DP solution
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<int> dp(n + 1, INT_MAX);
        for(int i = 1; i*i <= n; i++){
            squares.push_back(i*i);
        }
        dp[0] = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j < squares.size(); j++){
                if(squares[j] <= i){
                    dp[i] = min(dp[i], 1 + dp[i - squares[j]]);
                }
            }
        }
        
        return dp[n];
    }
};