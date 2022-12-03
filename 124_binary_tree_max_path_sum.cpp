/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int maxPathUtil(TreeNode* root, int &res){
        if(root == NULL)
            return 0;
        
        int l = maxPathUtil(root->left, res);
        int r = maxPathUtil(root->right, res);
        
        int temp = max(max(l,r) + root->val, root->val);
        int ans = max(temp , l + r + root->val);
        res = max(res, ans);
        
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathUtil(root, res);
        return res;
    }
};

// Solution 2
class Solution {
public:
    
    int solve(TreeNode* root, int &ans){
        if(!root)
            return 0;
        
        int leftSum = max(0, solve(root->left, ans));
        int rightSum = max(0, solve(root->right, ans));

        int temp = max(leftSum, rightSum) + root->val;
        
        int res = leftSum + rightSum + root->val;
        ans = max(res, ans);
        
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int temp = solve(root, ans);
        return ans;
    }
};