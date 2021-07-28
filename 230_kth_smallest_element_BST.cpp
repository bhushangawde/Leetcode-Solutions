class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(node != NULL || !st.empty()){
            while(node!=NULL){
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            k--;
            if(k==0) return node->val;
            node = node->right;
        }
        
        return -1;
    }
};