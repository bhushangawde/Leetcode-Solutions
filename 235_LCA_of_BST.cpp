class Solution {
public:
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