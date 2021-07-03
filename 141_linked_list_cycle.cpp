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
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        
        while (p && q) {
            p = p->next;
            q = q->next;
            if (q)
                q = q->next;
            else
                break;
            if (p == q)
                return true;
        }
        return false;
    }
};