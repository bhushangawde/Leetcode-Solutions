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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
	
	
	// Adding iterative solution #2
	/* vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        vector<int> vec;
        if(!root)
            return ans;
        
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                size--;
            }
            ans.push_back(vec);
            vec.clear();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    } */
	
	
	// Recursive solution
	
	/* vector<vector<int>> ans;
    
    void DFS(TreeNode* root, int level){
        if(!root){
            return;
        }
        
        if(level == ans.size()){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        DFS(root->left, level + 1);
        DFS(root->right, level + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        DFS(root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    } */
};