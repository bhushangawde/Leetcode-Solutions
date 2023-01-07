// Without reversing the output
class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   
        if(!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* output = NULL;
        int len1 = 0;
        int len2 = 0;
        
        while(first!=NULL){
            first = first -> next;
            len1++;
        }
        while(second!=NULL){
            second = second -> next;
            len2++;
        }

        first = l1;
        second = l2;
        if(len1 > len2){
            int d = len1 - len2;
            while(d--){
                ListNode *node = new ListNode(first->val);
                node -> next = output;
                output = node;
                first = first->next;
            }
        }
        else {
            int d = len2 - len1;
            while(d--){
                ListNode *node = new ListNode(second->val);
                node -> next = output;
                output = node;
                second = second->next;
            }
        }

        while(first && second){
            int add = first->val + second->val;
            ListNode *node = new ListNode(add);
            node -> next = output;
            output = node;
            first = first->next;
            second = second->next;
        }
        
        int carry = 0;
        ListNode* curr = output;
        ListNode* prev;
        while(curr){
            int val = curr->val + carry;
            carry = val / 10;
            curr->val = val % 10;
            prev = curr;
            curr = curr->next;
        }

        if(carry){
            ListNode *node = new ListNode(carry);
            prev -> next = node;
        }
        output = reverse(output);

        return output;
    }
};



//Reversing the input
class Solution {
public:

	// Reverse List 
	/*ListNode* reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        
        while(head)
        {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        
        return prev;
    }*/
	
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