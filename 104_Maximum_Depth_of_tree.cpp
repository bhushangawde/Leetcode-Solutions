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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else {
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            
            if(l>r)
                return 1+l;
            else
                return 1+r;
        }
    }
};