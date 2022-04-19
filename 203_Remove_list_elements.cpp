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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        
        while(head && head->val == val)
            head = head->next;
        
        ListNode *p = head;
        
        while(p && p->next){
            if(p->next->val == val){
                p->next = p->next->next;
            }
            else{
                p = p->next;
            }
        }
        
        return head;
    }
	
	
	
	// Sentinel node + delete the node with val = val
	/* ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        
        ListNode* sentinel = new ListNode(0, head);
        ListNode* curr = sentinel;
        
        while(curr->next){
            if(curr->next->val == val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        
        return sentinel->next;
    } */
};