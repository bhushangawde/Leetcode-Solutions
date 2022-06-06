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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* newHead = second;
        ListNode* prev = NULL;
        
        while(first && second){
            
            // Swapping the next of both nodes
            first->next = second->next;
            second->next = first;
            
            
            // Changing the next of previous node
            if(prev){
                prev->next = second;
            }
            
            // Shifting the pointers for the next run
            prev = first;
            first = first->next;
            if(first){
                second = first->next;
            }
        }
        return newHead;
    }
	
	
	// Recurrsive Solution
	/* ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
	
        ListNode *first = head;
        ListNode *second = head->next;
		
		// Swapping the first and second recursively
        first->next = swapPairs(second->next);
        second->next = first;
        
        return second;
            
    } */
};