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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        
        if(!root)
            return ans;
        st1.push(root);
        
        while(!st1.empty() || !st2.empty()){
            while(!st1.empty()){
                TreeNode *node = st1.top();
                st1.pop();
                temp.push_back(node->val);
    
                if(node->left)
                    st2.push(node->left);
                if(node->right)
                    st2.push(node->right);
            }
            if(temp.size() > 0){
                ans.push_back(temp);
                temp.clear();
            }
            while(!st2.empty()){
                TreeNode *node = st2.top();
                st2.pop();
                temp.push_back(node->val);
                
                if(node->right)
                    st1.push(node->right);
                if(node->left)
                    st1.push(node->left);
            }
            if(temp.size() > 0){
                ans.push_back(temp);
                temp.clear();
            }
        }
        
        return ans;
    }
};


// Another solution

/* class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool reverse = false;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> tempVec;
        queue<TreeNode*> q;
        stack<TreeNode*> st;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                temp = q.front();
                q.pop();
                if(reverse){
                    st.push(temp);
                }
                else{
                    tempVec.push_back(temp->val);
                }
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(reverse){
                while(!st.empty()){
                    temp = st.top();
                    st.pop();
                    tempVec.push_back(temp->val);
                }
            }
            reverse = !reverse;
            ans.push_back(tempVec);
            tempVec.resize(0);
        }
        
        return ans;
    }
}; */