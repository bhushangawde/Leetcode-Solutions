/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *p = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *nextNext = NULL;
        head = head->next;
        while(p && p->next){
            if(prev){
                prev->next = p->next;
            }
            next = p->next;
            nextNext = next->next;
            next->next = p;
            p->next = nextNext;
            prev = p;
            p=p->next;
        }
        
        return head;
    }
};