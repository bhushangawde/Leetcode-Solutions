class Solution {
public:

	// Iterative
	/* TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while(root!=NULL){
            if(root->val > p->val && root->val> q->val)
                root = root->left;
            
            else if(root->val < p->val && root->val < q->val)
                root = root->right;
            
            else
                break;    
        }
        return root;
    } */
	
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* x=root;
        if((x->val>=q->val && x->val<=p->val) || (x->val>=p->val && x->val<=q->val)){
            return x;
        }
        else if(x->val>q->val && x->val>p->val){
            return lowestCommonAncestor(x->left,p,q);
        }
        else{
            return lowestCommonAncestor(x->right,p,q);
        }
    }
};