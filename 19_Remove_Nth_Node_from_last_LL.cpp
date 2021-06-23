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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start=new ListNode();
        start ->next=head;
        ListNode *fast=start;
        ListNode *slow=start;
        
        for(int i=1;i<=n;i++)
            fast=fast->next;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};