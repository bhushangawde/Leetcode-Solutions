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
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        slow = slow->next;
        fast = fast->next->next;
        
        while(fast && fast->next){
            if(fast == slow)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(slow != fast)
            return NULL;
        
        slow = head;
        // int pos = 0;
        while(slow != fast){
            // pos++;
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};