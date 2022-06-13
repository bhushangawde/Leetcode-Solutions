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
    
    void reverse(ListNode* first, ListNode* last){
        ListNode *prev, *next, *curr;
        curr = first;
        prev = NULL;
        
        ListNode* stop = last->next;
        
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        while(curr != stop);
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *l1 = dummy;
        ListNode *l2 = dummy;
        ListNode* temp1, *temp2, *temp3;
        
        int itr = 0;
        
        while(itr < left - 1){
            l1 = l1->next;
            l2 = l2->next;
            itr++;
        }
        
        while(itr < right){
            l2 = l2->next;
            itr++;
        }

        temp1 = l2->next;
        reverse(l1->next, l2);
        l1->next->next = temp1;
        l1->next = l2;
        
        
        return dummy->next;
    }
};