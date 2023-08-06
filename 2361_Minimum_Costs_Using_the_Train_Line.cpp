// Bottom up simplified solution
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int stops = regular.size() + 1;
        vector<vector<long long>> dp(stops, vector<long long>(2, 0));
        vector<long long> ans;
        dp[0][0] = 0;
        dp[0][1] = expressCost;


        for(int i = 1; i < stops; i++){
            long long reg_reg = dp[i - 1][0] + regular[i - 1];
            long long exp_reg = dp[i - 1][1] + regular[i - 1];
            dp[i][0] = min(reg_reg, exp_reg);


            long long reg_exp = dp[i - 1][0] + expressCost + express[i - 1];  
            long long exp_exp = dp[i - 1][1] + express[i - 1];
            dp[i][1] = min(reg_exp, exp_exp);

            ans.push_back(min(dp[i][1], dp[i][0]));
        }

        return ans;
    }
};



// Bottom up solution
class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int stops = regular.size() + 1;
        vector<vector<long long>> dp(stops, vector<long long>(2, 0));
        vector<long long> ans;
        dp[0][0] = 0;
        dp[0][1] = expressCost;


        for(int i = 1; i < stops; i++){
            long long reg_reg = min(dp[i - 1][0] + regular[i - 1], dp[i - 1][0] + expressCost + express[i - 1]);
            long long reg_exp = min(dp[i - 1][1] + regular[i - 1], dp[i - 1][1] + express[i - 1]);

            dp[i][0] = min(reg_reg, reg_exp);


            long long exp_reg = min(dp[i - 1][0] + regular[i - 1] + expressCost, dp[i - 1][0] + expressCost + express[i - 1]);  
            long long exp_exp = min(dp[i - 1][1] + express[i - 1], dp[i - 1][1] + regular[i - 1] + expressCost);
            dp[i][1] = min(exp_reg, exp_exp);
			
            ans.push_back(min(dp[i][1], dp[i][0]));
        }

        return ans;
    }
};