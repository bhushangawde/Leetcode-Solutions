/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        else {
            int l = maxDepth(root->left);
            int r = maxDepth(root->right);
            
            if(l>r)
                return 1+l;
            else
                return 1+r;
        }
    }
	
	// Iterative solution
	
	/* int maxDepth(TreeNode* root) {
        
        queue<TreeNode*> q;
        int depth=0;
        if(root==NULL)
            return depth;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            depth++;
            for(int i=1; i<=n; i++)
            {
                TreeNode* node =q.front();
                q.pop();
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
        }
        
        return depth;
        
    } */
};