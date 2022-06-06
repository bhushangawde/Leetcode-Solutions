/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kth_begin = head;
        ListNode *kth_end = head;
        ListNode *node = head;
        
        int i = 1;
        while(i < k){
            kth_begin = kth_begin->next;
            node = node->next;
            i++;
        }
        
        while(node->next){
            node = node->next;
            kth_end = kth_end->next;
        }
        
        
        swap(kth_begin->val, kth_end->val);
        
        // int temp = kth_end->val;
        // kth_end->val = kth_begin->val;
        // kth_begin->val = temp;
        
        
        return head;
    }
};