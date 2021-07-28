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
    
	bool isSymmetricIter(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        
        while(!q.empty()){
            TreeNode* t1 = q.front();
            q.pop();
            TreeNode* t2 = q.front();
            q.pop();
            
            if(t1 == NULL && t2 == NULL)
                continue;
            if(t1 == NULL || t2 == NULL)
                return false;
            if(t1->val != t2->val)
                return false;
            
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
    
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