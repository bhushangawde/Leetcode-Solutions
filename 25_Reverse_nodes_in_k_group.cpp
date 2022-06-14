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
    
    ListNode* reverse(ListNode* first, int k){
        ListNode *prev, *next, *curr;
        curr = first;
        prev = NULL;
        while(k--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *l1 = head;
        ListNode *l2 = head;
        ListNode* prevEnd = dummy;
        
        while(l1 != NULL){
            int count = 1;
            while(count<k && l2){
                l2 = l2->next;
                count++;
            }
            if(l2)
                l2 = l2->next;
            else
                break;
                
            prevEnd->next = reverse(l1,k);
            prevEnd = l1;
            l1->next = l2;
            l1 = l2;
        }
        
        return dummy->next;
    }
};