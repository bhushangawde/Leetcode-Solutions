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
    TreeNode *create(vector<int>& preorder, vector<int>& inorder , int s , int e, int &index){
        if(s>e || index > preorder.size()-1)
            return NULL;
        
        int curr = preorder[index++];
        struct TreeNode* tNode = new TreeNode(curr);
        
        int i; 
        for (i = s; i <= e; i++) { 
            if (inorder[i] == curr) 
                break; 
        } 
        int mid = i;
        tNode->left = create(preorder,inorder,s,mid-1,index);
        tNode->right = create(preorder,inorder,mid+1,e,index);
        
        return tNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size =  preorder.size();
        int index = 0;
        return create(preorder, inorder,0,size-1,index);
    }
};