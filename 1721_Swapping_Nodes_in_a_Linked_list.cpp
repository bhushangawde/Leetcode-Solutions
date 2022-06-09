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
	
	
	// Swapping nodes instead of values
	/* ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *kth_begin = dummy;
        ListNode *kth_end = dummy;
        ListNode *node = dummy;
        ListNode *prev_1 = dummy;
        ListNode *prev_2 = dummy;
        
        
        int i = 0;
        while(i < k){
            prev_1 = kth_begin;
            kth_begin = kth_begin->next;
            node = node->next;
            i++;
        }
        
        while(node){
            node = node->next;
            prev_2 = kth_end;
            kth_end = kth_end->next;
        }
        
        if(kth_begin->next == kth_end){
            prev_1->next = kth_end;
            kth_begin->next = kth_end->next;
            kth_end->next = kth_begin;
        }
        else{
            prev_1->next = kth_end;
            ListNode *temp = kth_end->next;
            kth_end->next = kth_begin->next;
            kth_begin->next = temp;
            prev_2->next = kth_begin;
        }
        
        return dummy->next;
    } */
};