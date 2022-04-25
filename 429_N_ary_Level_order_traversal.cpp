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
                for(auto x : node->children){
                    q.push(x);
                }
            }
        }
        if(tempVec.size() > 0){
            ans.push_back(tempVec);
        }
        return ans;
    }
};