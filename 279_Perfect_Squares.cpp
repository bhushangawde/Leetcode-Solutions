// Recursion
class Solution {
public:

    int solve(vector<int> &squares, int n){
        if(n <= 0)
            return 0;
        int minNums = INT_MAX;
        for(int i = 0 ; i < squares.size(); i++){
            if(squares[i] <= n){
                minNums = min(minNums, 1 + solve(squares, n - squares[i]));
            }
        }
        return minNums;
    }

    int numSquares(int n) {
        vector<int> squares;
        vector<int> dp(n + 1, INT_MAX);
        for(int i = 1; i*i <= n; i++){
            squares.push_back(i*i);
        }
        return solve(squares, n);
    }
};

// Recursion + memoization
class Solution {
public:

    int solve(vector<int> &squares, int n, vector<int> &dp){
        if(n <= 0)
            return 0;
        if(dp[n] != INT_MAX)
            return dp[n];
        int minNums = INT_MAX;
        for(int i = 0 ; i < squares.size(); i++){
            if(squares[i] <= n){
                minNums = min(minNums, 1 + solve(squares, n - squares[i], dp));
            }
        }
        return dp[n] = minNums;
    }

    int numSquares(int n) {
        vector<int> squares;
        vector<int> dp(n + 1, INT_MAX);
        for(int i = 1; i*i <= n; i++){
            squares.push_back(i*i);
        }
        return solve(squares, n, dp);
    }
};

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


// BFS
class Solution {
public:

    int numSquares(int n) {
        vector<int> squares;
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;
        int currCnt = 1;
        queue<int> qs;
        for(int i = 1; i*i <= n; i++){
            squares.push_back(i*i);
            dp[i*i] = 1;
            qs.push(i*i);
        }

        if(n == qs.back())
            return 1;
            
        while(!qs.empty()){
            currCnt++;
            int size = qs.size();
            for(int s = 0; s < size; s++){
                int temp = qs.front();
                for(int i = 0 ; i < squares.size(); i++){
                    int val = temp + squares[i];
                    if(val > n)
                        break;
                    else if(val == n)
                        return currCnt;
                    else if(val < n && dp[val] == INT_MAX){
                        dp[val] = currCnt;
                        qs.push(val);
                    }
                }
                qs.pop();
            } 
        }
        return 0;
    }
};