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
   
	
	/* bool pathSum(TreeNode *root, int sum, int &curr){
        if( root==NULL)
            return false;
        
        curr = curr + root->val;
        
        if(curr==sum && root->left==NULL && root->right==NULL)
            return true;
        
        if(pathSum(root->left,sum,curr) || pathSum(root->right,sum,curr))
            return true;
        
        curr = curr - root->val;
        return false;
    }    
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        int curr=0;
        return(pathSum(root,sum,curr));
    } */
	
	// Updated Solution
	bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        if(targetSum == root->val && !root->left && !root->right)
            return true;
        
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
        
    }
	
	
	// Iterative solution
	/* bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        stack<TreeNode*> nodeSt;
        stack<int> sumSt;
        nodeSt.push(root);
        sumSt.push(sum - root->val);
        
        while(!nodeSt.empty()){
            TreeNode* node = nodeSt.top();
            nodeSt.pop();
            
            int val = sumSt.top();
            sumSt.pop();
            
            if(val == 0 && !node->left && !node->right){
                return true;
            }
            
            if(node->left){
                nodeSt.push(node->left);
                sumSt.push(val - node->left->val);
            }
            if(node->right){
                nodeSt.push(node->right);
                sumSt.push(val - node->right->val);
            }
        }
        
        return false;
    } */
};