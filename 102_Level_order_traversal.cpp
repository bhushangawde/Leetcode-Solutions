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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        if(root ==NULL)
            return ans;
        q.push(root);
        q.push(NULL);
        vector<int> x;
        x.push_back(root->val);
        ans.push_back(x);
        x.clear();
        while(q.size()>1){
            
            TreeNode *node = q.front();
            q.pop();
            if(node==NULL){
                q.push(NULL);
                ans.push_back(x);
                x.clear();
            }
            else{
                if(node->left){
                    q.push(node->left);
                    x.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    x.push_back(node->right->val);
                }
            }
        }
        return ans;
    }
};