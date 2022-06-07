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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *prev = NULL;
        int k = 0;
        while(k<n){
            q=q->next;
            k++;
        }
        while(q!=NULL){
            prev = p;
            q=q->next;
            p=p->next;
        }
        if(prev==NULL){
            return head->next;
        }
        else{
            prev->next = prev->next->next;
            return head;
        }
        
    }
};


// Solution 2

/* class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy =new ListNode();
        dummy->next=head;
        ListNode *prev=dummy;
        ListNode *curr=dummy;
        
        int i = 0;
        while(i < n){
            curr = curr->next;
            i++;
        }
        
        while(curr->next){
            curr = curr->next;
            prev = prev->next;
        }
        
        prev->next = prev->next->next;
        return dummy->next;
    }
}; */