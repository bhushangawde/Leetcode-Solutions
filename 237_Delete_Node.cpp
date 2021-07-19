class Solution {
public:
    void deleteNode(ListNode* node) {
        // int x = node->val;
        node->val = node->next->val; 
        node->next = node->next->next;
    }
};