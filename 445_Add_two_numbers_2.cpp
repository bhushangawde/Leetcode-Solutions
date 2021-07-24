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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   
        if(!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* output = NULL;
        vector <int> num1, num2;
        int len1 = 0;
        int len2 = 0;
        
        while(first!=NULL){
            num1.push_back(first->val);
            first = first -> next;
            len1++;
        }
        while(second!=NULL){
            num2.push_back(second->val);
            second = second -> next;
            len2++;
        }
        // cout<<len1<<endl;
        // cout<<len2<<endl;
        int sum = 0;
        int carry = 0;
        for(int i = len1 - 1, j = len2 - 1; i>=0 || j>=0 || carry > 0; i--,j--){
            sum = carry;
            if(i >= 0)
                sum += num1[i];
            if(j >= 0)
                sum += num2[j];
            
            carry = sum / 10;
            
            ListNode *node = new ListNode(sum%10);
            node -> next = output;
            output = node;
        }
        
        return output;
    }
};