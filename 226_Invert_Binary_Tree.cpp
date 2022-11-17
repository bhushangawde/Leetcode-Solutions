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
    
    void mirror(TreeNode* root){
        if(!root)
            return;
        
        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
    }

    void mirrorIter(TreeNode* root){
        if(!root)
            return;

        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            TreeNode* curr = qu.front();
            qu.pop();
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if(curr->left)
                qu.push(curr->left);
            if(curr->right)
                qu.push(curr->right);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        // mirror(root);
        mirrorIter(root);
        return root;
    }
};