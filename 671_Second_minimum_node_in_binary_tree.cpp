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
    
    long solve(TreeNode* root, int rootVal){
        if(!root){
            return LLONG_MAX;
        }
        if(root->val != rootVal){
            return root->val;
        }
        
        long left = solve(root->left, rootVal);
        long right = solve(root->right, rootVal);
        
        return min(left, right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        long element = solve(root, root->val);
        if(element == LLONG_MAX)
            return -1;
        return element;
    }
};