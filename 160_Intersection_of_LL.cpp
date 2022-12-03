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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* hA = headA;
        ListNode* hB = headB;
        bool fA = false, fB = false;
        if(!headA || !headB)
            return NULL;

        while(hA != hB && hA && hB){
            
            hA = hA->next;
            hB = hB->next;

            if(hA == NULL && !fA){
                hA = headB;
                fA = true;
            }
            
            if(hB == NULL && !fB){
                hB = headA;
                fB = true;
            }
        }
        if(hA)
            return hA;
        return NULL;
    }
};

/* ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == p2) return p1;
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
    return p1;
}
 */