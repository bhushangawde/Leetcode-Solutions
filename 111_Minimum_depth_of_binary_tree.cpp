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

	// Iterative
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty()){
            int size = q.size();
            depth++;
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(!node->left && !node->right)
                    return depth;
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
        }
        return depth;
    }
};