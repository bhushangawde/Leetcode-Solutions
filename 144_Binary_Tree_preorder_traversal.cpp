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
    
    void preorder(TreeNode* root, vector<int> &vec){
        if(root!=NULL){
            vec.push_back(root->val);
            preorder(root->left, vec);
            preorder(root->right, vec);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preorder(root, vec);
        return vec;
    }
	
	
	
	//Iterative solution using stack
	/* vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st;
        
        if(root == NULL)
            return vec;
        
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            vec.push_back(curr->val);
            
            if(curr->right)
                st.push(curr->right);
            
            if(curr->left)
                st.push(curr->left);
        }
        
        return vec;
    } */
};