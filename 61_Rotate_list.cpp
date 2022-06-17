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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;
    
        int len = 1;
        ListNode *curr = head;
        while(curr->next){
            len++;
            curr = curr->next;
        }
        
        k = k % len;
        if(k == 0)
            return head;
        
        ListNode* tail = head;
        ListNode *newHead = NULL;
        
        
        int count = 1;
        while(count < len - k){
            tail = tail->next;
            count++;
        }
        
        newHead = tail->next;
        tail->next = NULL;
        curr->next = head;
        
        return newHead;
    }
};