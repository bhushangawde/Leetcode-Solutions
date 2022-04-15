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
    /* ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        if(!l1 && !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode *L = new ListNode(0);
        ListNode *temp = L;
        while(l1 || l2){
            
            if(l1 && l2){
                int val = l1->val + l2->val + carry;
                if(val >= 10)
                    carry = 1;
                else 
                    carry = 0;
                
                val = val%10;
                L->next = new ListNode(val);
                L = L->next;
                l1 = l1->next;
                l2 = l2->next;
                continue;
            }
            
            if(l1){
                int val = l1->val + carry;
                if(val >= 10)
                    carry = 1;
                else
                    carry = 0;
                
                val = val%10;
                L->next = new ListNode(val);
                L = L->next;
                l1 = l1->next;
                continue;
            }
            
            
            if(l2){
                int val = l2->val + carry;
                if(val >= 10)
                    carry = 1;
                else
                    carry = 0;
                
                val = val%10;
                L->next = new ListNode(val);
                L = L->next;
                l2 = l2->next;
                continue;
            }
            
        }
        if(carry){
            L->next = new ListNode(1);
        }
        return temp->next;
    } */
	
	
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode *dummy = new ListNode(0, NULL);
        ListNode* tail = NULL;
        while(l1 || l2){
            int val1 = 0;
            if(l1){
                val1 = l1->val;
            }
            int val2 = 0;
            if(l2){
                val2 = l2->val;
            }
            int sum = val1 + val2 + carry;
            carry = sum/10;
            
            if(!tail){
                tail = new ListNode(sum%10);
                dummy->next = tail;
            }
            else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            
        }
        
        if(carry){
            tail->next = new ListNode(1);
        }
        
        return dummy->next;
    }
};