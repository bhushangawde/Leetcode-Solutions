class Solution {
public:
    
    // min-heap
    /* int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int n : nums){
            pq.push(n);
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }*/
    
    
    // max-heap
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq (nums.begin(), nums.end());
        
        for(int n = 0; n < k-1; n++){
            pq.pop();
        }
        
        return pq.top();
    }
    
};