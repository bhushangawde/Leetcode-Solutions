/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& x){
        if(root == NULL)
            return;
        inOrder(root->left,x);
        x.push_back(root->val);
        
        inOrder(root->right,x);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans = {};
        if(root==NULL)
            return ans;
        inOrder(root,ans);
        return ans;
    }
};