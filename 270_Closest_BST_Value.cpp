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
    int closestValue(TreeNode* root, double target) {
        int closestValue = -1;
        double minDiff = INT_MAX;
        while(root){
            
            if(abs(root->val - target) < minDiff || (abs(root->val - target) == minDiff && root->val < closestValue)){
                minDiff = abs(root->val - target);
                closestValue = root->val;
            }
            if(root->val < target){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return closestValue;
    }
};