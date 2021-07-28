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
    
    
    bool sym(TreeNode *root1,TreeNode *root2){
        if(root1==NULL && root2 ==NULL)
            return true;
        
        if(root1 ==NULL ||root2 ==NULL)
            return false;
        if (root1->val == root2->val && sym(root1->left,root2->right) && sym(root1->right,root2->left))
            return true;
        return false;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return sym(root,root);
            
        
    }
};