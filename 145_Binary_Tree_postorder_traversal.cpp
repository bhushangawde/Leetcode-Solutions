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
    
    void postorder(TreeNode* root, vector<int> &vec){
        if(root!=NULL){
            postorder(root->left, vec);  
            postorder(root->right, vec);
            vec.push_back(root->val);
              
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        postorder(root, vec);
        return vec;
    }
	
	
	// Iterative solution using stack without reverse
	/* vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        stack<TreeNode*> st;
        TreeNode *prev = NULL;
        if(!root){
            return vec;
        }
        
        while(!st.empty() || root!= NULL){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* node = st.top();
                if(node->right && prev != node->right){
                    root = node->right;
                }
                else{
                    vec.push_back(node->val);
                    st.pop();
                    prev = node;
                }
            }
        }
        
        return vec;
    } */
	
	// Iterative solution using stack with reverse function
	/* vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        stack<TreeNode*> st;
        
        if(!root){
            return vec;
        }
        
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            vec.push_back(node->val);
            
            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
        }
        reverse(vec.begin(), vec.end());
        return vec;
    } */
};