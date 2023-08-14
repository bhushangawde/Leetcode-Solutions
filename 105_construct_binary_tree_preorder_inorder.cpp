// Fast solution - O(N) time 
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
    TreeNode* buildTreeSolve(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &ump, int &preIndex, int inStart, int inEnd) {

        if(inStart > inEnd)
            return NULL;
        
        TreeNode *node = new TreeNode(preorder[preIndex++]);

        if(inStart == inEnd)
            return node;
        
        int idx = ump[node->val];

        node->left = buildTreeSolve(preorder, inorder, ump, preIndex, inStart, idx - 1);
        node->right = buildTreeSolve(preorder, inorder, ump, preIndex, idx + 1, inEnd);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ump;
        int size = inorder.size();
        for(int i = 0 ; i < size; i++)
            ump[inorder[i]] = i;
        int preIndex = 0;
        return buildTreeSolve(preorder, inorder, ump, preIndex, 0, size - 1);
    }
};

// Slow solution O(n2)
/* 
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
}; */