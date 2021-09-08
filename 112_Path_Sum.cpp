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
   
    
    bool pathSum(TreeNode *root, int sum, int &curr){
        if( root==NULL)
            return false;
        
        curr = curr + root->val;
        //cout<<"curr:"<<curr<<endl;
        if(curr==sum && root->left==NULL && root->right==NULL)
            return true;
        
        
        
        if(pathSum(root->left,sum,curr) || pathSum(root->right,sum,curr))
            return true;
        else{
            curr = curr - root->val;
            return false;
        }
    }    
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        int curr=0;
        return(pathSum(root,sum,curr));
    }
};