

// Bottom Up O(n2)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int maxLen = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    maxLen = max(maxLen, dp[i][j]);
                }
                else 
                    dp[i][j] = 0;
            }
        }
        return maxLen;
    }
};


//  Top Down Recursion + Memoization
class Solution {
public:
    int ans = 0;
    int solve(vector<int>& nums1, vector<int>& nums2, int n1, int n2, vector<vector<int>> &dp){
        if(n1 < 0 || n2 < 0){
            return 0;
        }
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
        solve(nums1, nums2, n1-1, n2, dp);
        solve(nums1, nums2, n1, n2-1, dp);
        int temp = 0;
        if(nums1[n1] == nums2[n2]){
            temp = 1 + solve(nums1, nums2, n1-1, n2-1, dp);
        }
        ans = max(ans, temp);
        return dp[n1][n2] = temp;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        solve(nums1, nums2, n1-1, n2-1, dp);
        return ans;
    }
};


//  Top Down Recursion
class Solution {
public:
    int ans = 0;
    int solve(vector<int>& nums1, vector<int>& nums2, int n1, int n2){
        if(n1 < 0 || n2 < 0){
            return 0;
        }
        solve(nums1, nums2, n1-1, n2);
        solve(nums1, nums2, n1, n2-1);
        int temp = 0;
        if(nums1[n1] == nums2[n2]){
            temp = 1 + solve(nums1, nums2, n1-1, n2-1);
        }
        ans = max(ans, temp);
        return temp;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        solve(nums1, nums2, n1-1, n2-1);
        return ans;
    }
};