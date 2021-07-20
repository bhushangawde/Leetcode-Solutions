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
    
    int res = 0 ; 
    int rank = 0;
    
    void kthSmall(TreeNode* root, int k){
        if(root != NULL){
            kthSmall(root->left, k);
            rank++;
            if(rank == k){
                res = root->val;
                return;
            }
            kthSmall(root->right, k);
        }
    } 
    
    int kthSmallest(TreeNode* root, int k) {
        kthSmall(root, k);
        return res;
    }
    
//     void kthSmall(TreeNode* root, vector <int> &v){
//         if(root != NULL){
//             kthSmall(root->left, v);
//             v.push_back(root->val);
//             kthSmall(root->right, v);
//         }
//     } 
    
//     int kthSmallest(TreeNode* root, int k) {
//         vector <int> vec ; 
//         kthSmall(root, vec);
//         return vec[k-1];
//     }
};