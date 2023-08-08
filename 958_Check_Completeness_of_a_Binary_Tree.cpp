// Shorter solution
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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(!node){
                    nullFound = true;
                }
                else {
                    if(nullFound){
                        return false;
                    }
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true;
    }
};




// Level Order Traversal
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    if(nullFound){
                        return false;
                    }
                    q.push(node->left);
                }
                else{
                    nullFound = true;
                }

                if(node->right){
                    if(nullFound){
                        return false;
                    }
                    q.push(node->right);
                }
                else {
                    nullFound = true;
                }
            }
        }
        return true;
    }
};