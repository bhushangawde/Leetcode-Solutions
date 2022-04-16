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
    
    int solve(ListNode *head){
        if(head == NULL){
            return 1;
        }
        int carry = solve(head->next);
        if(head->val == 9 && carry == 1){
            head->val = 0;
            return 1;
        }
        else{
            head->val += carry;
            return 0;
        }
    }
    ListNode* plusOne(ListNode* head) {
        int carry = solve(head);
        if(carry){
            ListNode* newNode = new ListNode(1,head);
            return newNode;
        }
        return head;
    }
};