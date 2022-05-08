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
    
    bool isBST(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root) 
            return true;
        if(max != NULL && root->val >= max->val)
            return false;
        
        if(min != NULL && root->val <= min->val)
            return false;
        
        return isBST(root->left, min, root) && isBST(root->right, root, max);
        
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
};



// Solution using inorder traversal

/* class Solution {
public:
    
    TreeNode* prev = NULL;
    
    bool inorder(TreeNode *root){
        if(!root)
            return true;
        
        if(!inorder(root->left)){
            return false;
        }
        if(prev && root->val <= prev->val){
            return false;
        }
        prev = root;
        
        return inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        return inorder(root);   
    }
}; */