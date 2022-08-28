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

// Best Solution O(n) time and O(1) space 
class Solution {
public:
    
    int getLeaves(TreeNode *root, vector<vector<int>>& ans){
        if(!root)
            return -1;
        
        int l = getLeaves(root->left, ans);
        int r = getLeaves(root->right, ans);
        int height = 1 + max(l, r);
        if(ans.size() < height + 1)
            ans.resize(height + 1);
        ans[height].push_back(root->val);
        
        return height;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        getLeaves(root, ans);
        return ans;
    }
};


 // Brute force approach by removing the node O(n2) time and O(n) space
class Solution {
public:
    
    void getLeaves(TreeNode *root, vector<int>& vec, unordered_multimap<TreeNode*, char>& ump){
        if(!root)
            return;
        getLeaves(root->left, vec, ump);
        getLeaves(root->right, vec, ump);
        
        if(root->left && root->left->left == NULL && root->left->right == NULL){
            vec.push_back(root->left->val);
            ump.insert(make_pair(root, 'l'));
        }
        
        if(root->right && root->right->left == NULL && root->right->right == NULL){
            vec.push_back(root->right->val);
            ump.insert(make_pair(root, 'r'));
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        
        while(1){
            vector<int> vec;
            unordered_multimap<TreeNode*, char> ump;
            vector<TreeNode*> vecPtr;
            if(root->left == NULL && root->right == NULL){
                vec.push_back(root->val);
                ans.push_back(vec);
                break;
            }
            else{
                getLeaves(root, vec, ump);
                for(auto ele: ump){
                    if(ele.second == 'l')
                        ele.first->left = NULL;
                    else if(ele.second == 'r')
                        ele.first->right = NULL;
                }
                ans.push_back(vec);
            }
        }
        return ans;
    }
};