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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        vector<int> tempVec;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size() > 1){
            Node* node = q.front();
            q.pop();
            
            if(node == NULL){
                q.push(NULL);
                ans.push_back(tempVec);
                tempVec.clear();
            }
            else{
                // cout<<node->val<<endl;
                tempVec.push_back(node->val);
                for(int i = 0; i < node->children.size(); i++){
                    q.push(node->children[i]);
                }
            }
        }
        if(tempVec.size() > 0){
            ans.push_back(tempVec);
        }
        return ans;
    }
	
	// Recursive solution
	
	/* vector<vector<int>> ans;
    
    void DFS(Node* root, int level){
        if(!root)
            return;
        if(level == ans.size()){
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        for(int i = 0 ; i < root->children.size(); i++){
            DFS(root->children[i], level + 1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return ans;
        }
        DFS(root, 0);
        return ans;
    } */
	
};