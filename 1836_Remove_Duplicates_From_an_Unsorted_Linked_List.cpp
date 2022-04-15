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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if(!head->next){
            return head;
        }
        int ump[100001] = {0};
        ListNode *node = new ListNode(0,head);
        ListNode *curr = head;
        ListNode *newHead = NULL;
        
        while(curr){
            ump[curr->val] += 1;
            curr = curr->next;
        }
        
        curr = head;
        while(curr){
            if(ump[curr->val] > 1){
                node->next = node->next->next;
                curr = curr->next;
            }
            else{
                if(!newHead){
                    newHead = node->next;
                }
                curr = curr->next;    
                node = node->next;
            }            
        }
        
        return newHead;
    }
};