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
    
    int solve(Node* root, int &result){
        if(root == NULL)
            return 0;
        
        int max1 = 0;
        int max2 = 0;
        for(auto it : root->children){
            int h = solve(it, result);
            
            if(h > max2){
                max1 = max2;
                max2 = h;
            }
            else if (h > max1){
                max1 = h;
            }
        }
        
        int temp = max(max1, max2) + 1;
        // int ans = max(temp, max1 + max2);
        result = max(result, max1 + max2);
        
        return temp;
        
    }
    
    int diameter(Node* root) {
        int res = 0;
        int h = solve(root, res);
        return res;
    }
};