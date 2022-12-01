// O(n) space solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev(201, INT_MAX);
        vector<int> curr(201, INT_MAX);
        
        int size = triangle.size();
        prev[1] = triangle[0][0];
        
        for(int i = 2; i <= size; i++){
            for(int j = 1; j <= i; j++){
                curr[j] = triangle[i - 1][j - 1] + min(prev[j - 1], prev[j]);
            }
            prev = curr;
        }
       
        int min_ = INT_MAX;
        for(int i = 1; i <= size; i++){
            min_ = min(min_, prev[i]);
        }
        return min_;
    }
};

// O(n2) space solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[201][201];
        
        for(int i = 0; i < 201; i++){
            for(int j = 0 ; j < 201; j++){
                dp[i][j] = 10001;
            }
        }
        
        int size = triangle.size();
        dp[1][1] = triangle[0][0];
        

        for(int i = 2; i <= size; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = triangle[i - 1][j - 1] + min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
       
        int min_ = 10001;
        for(int i = 1; i <= size; i++){
            min_ = min(min_, dp[size][i]);
        }
        return min_;
    }
};