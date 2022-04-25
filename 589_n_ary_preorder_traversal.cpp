/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void preorderRecursive(Node* root, vector<int> &ans){
        if(!root){
            return;
        }
        ans.push_back(root->val);
        for(auto node : root->children){
            preorderRecursive(node, ans);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorderRecursive(root, ans);
        return ans;
    }
	
	//Iterative solution
	
	/* vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            ans.push_back(node->val);
            
            for(int i = node->children.size() - 1; i >= 0; i--){
                st.push(node->children[i]);
            }
        }
        return ans;
    } */
};