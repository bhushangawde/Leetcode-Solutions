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

	// Iteratie solution using queue O(n) space
	bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        
        queue<TreeNode *> que;
        que.push(p);
        que.push(q);
        
        while(!que.empty()){
            TreeNode *first = que.front(); que.pop();
            TreeNode *second = que.front(); que.pop();
            
            if(first == NULL && second == NULL)
                continue;
            if(first == NULL || second == NULL)
                return false;
            if(first->val != second->val)
                return false;
            
            que.push(first->left);
            que.push(second->left);
            que.push(first->right);
            que.push(second->right);
        }
        
        return true;
    }
	
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};