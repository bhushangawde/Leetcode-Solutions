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
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return true;
        int curr = root->val;
        int lnode = -1, rnode = -1;
        if(root->left)
            lnode = root->left->val;
        if(root->right)
            rnode = root->right->val;
        // cout<<"Lnode "<<lnode<<endl;
        // cout<<"Rnode "<<rnode<<endl;
        bool flagl = true, flagr = true;
        if(lnode > -1 && lnode != curr)
            flagl = false;
        if(rnode > -1 && rnode != curr)
            flagr = false;
        
        if(flagl && flagr && isUnivalTree(root->left) && isUnivalTree(root->right))
            return true;
        
        return false;
    }
};