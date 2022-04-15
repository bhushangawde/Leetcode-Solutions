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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next == NULL)
            return head;
        
        ListNode *newHead = NULL;
        ListNode* curr = new ListNode(-101);
        curr->next = head;
        
        while(curr){
            if(curr->next && curr->next->next && curr->next->val == curr->next->next->val){
                int val = curr->next->val;
                ListNode* p = curr->next;
                while(p && p->val == val){
                    p = p->next;
                }
                curr->next = p;
            }
            else{
                if(!newHead){
                    newHead = curr;
                }
                curr = curr->next;
            }
        }
        return newHead->next;
    }
};