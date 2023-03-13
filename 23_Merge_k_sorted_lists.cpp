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
 
 
 // USING A PRIORITY QUEUE - STL
class Solution {
public:
    struct compare{
        bool operator()(ListNode *first, ListNode *second){
            return first->val > second->val;
        }
    };
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-10001, NULL);
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* newHead = NULL;
        ListNode* currPtr = dummy;
        
        for(int i = 0 ; i < lists.size(); i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        
        while(!pq.empty()){
            ListNode* currMin = pq.top();
            pq.pop();
            currPtr->next = currMin;
            currPtr = currMin;
            ListNode *next = currMin->next; 
            if(next){
                pq.push(next);
            }
        }
        
        return dummy->next;
    }
};

// USING MERGE TWO LISTS AT A TIME - CHANGES THE INPUT LISTS
/* class Solution {
public:
    ListNode* mergeTwoLists(ListNode *first, ListNode* second){
        ListNode* dummy = new ListNode(-10001, NULL);
        ListNode* curr = dummy;
        while(first && second){
            if(first->val < second->val){
                curr->next = first;
                first = first->next;
                curr = curr->next;
            }
            else{
                curr->next = second;
                second = second->next;
                curr = curr->next;
            }
        }
        
        if(first)
            curr->next = first;
        if(second)
            curr->next = second;
        
        return dummy->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return {};
        int len = lists.size();
        while(len > 1){
            for(int i = 0; i < len/2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
            }
            len = (len + 1)/2;
        }
        return lists[0];
    }
}; */