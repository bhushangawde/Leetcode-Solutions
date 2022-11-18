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
    void solve(TreeNode* node, int &sum, int &currSum){
        if(!node){
            return;
        }
        currSum = currSum*10 + node->val;
        if(!node->left && !node->right){
            sum += currSum;
            currSum = (currSum - node->val)/10;
            return;
        }
        
        solve(node->left, sum, currSum);
        solve(node->right, sum, currSum);
        currSum = (currSum - node->val)/10;
    }

    int sumNumbers(TreeNode* root) {
        int currSum = 0;
        int sum = 0;
        solve(root, sum, currSum);
        return sum;
    }
};

// Pass by value
class Solution {
public:

    int solve(TreeNode* node, int currSum){
        if(!node){
            return 0;
        }
        currSum = currSum*10 + node->val;
        if(!node->left && !node->right){
            return currSum;
        }
        return solve(node->left, currSum) + solve(node->right, currSum);
    }

    int sumNumbers(TreeNode* root) {
        int currSum = 0;
        int sum = solve(root, currSum);
        return sum;
    }
};

// Iterative using stack
class Solution {
public:

    int solveIter(TreeNode* node){
        stack<pair<TreeNode*, int>>st;
        st.push({node, 0});
        int sum = 0;
        while(!st.empty()){
            pair<TreeNode*, int> p = st.top();
            st.pop();
            int currSum = p.second;
            TreeNode* temp = p.first;
            currSum = currSum*10 + temp->val;
            if(!temp->left && !temp->right)
                sum += currSum;
            if(temp->left)
                st.push({temp->left, currSum});
            if(temp->right)
                st.push({temp->right, currSum});
        }
        return sum;
    }

    int sumNumbers(TreeNode* root) {
        int currSum = 0;
        // int sum = solve(root, currSum);
        int sum = solveIter(root);
        return sum;
    }
};