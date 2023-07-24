

// Recursion

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

    vector<TreeNode*> solve(int start, int end){
        if(start > end){
            return {NULL};
        }

        vector<TreeNode*> ans;

        for(int node = start; node <= end; node++){
            vector<TreeNode*> left = solve(start, node - 1);
            vector<TreeNode*> right = solve(node + 1, end);

            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(node);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;

    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};