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
    
        int count = 0;
        ListNode *curr = head;
        while(curr){
            count++;
            curr = curr->next;
        }
        
        if(k >= count){
            k = k % count;
        }
        
        if(k == 0)
            return head;
        
        curr = head;
        ListNode* tail = head;
        ListNode *newHead = NULL;
        count = 0;
        while(count < k){
            curr = curr->next;
            count++;
        }
        while(curr->next){
            curr = curr->next;
            tail = tail->next;
        }
        
        newHead = tail->next;
        tail->next = NULL;
        curr->next = head;
        
        return newHead;
    }
};