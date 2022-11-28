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
    
	// Min-heap alternate implementation
/* 	int findKthLargest(vector<int>& nums, int k) {
		multiset<int> mset;
		for (int num : nums) {
			mset.insert(num);
			if (mset.size() > k) {
				mset.erase(mset.begin());
			}
		}
		return *mset.begin();
	}
 */    
 
    // max-heap
    /* int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq (nums.begin(), nums.end());
        
        for(int n = 0; n < k-1; n++){
            pq.pop();
        }
        
        return pq.top();
    } */
	
	
	// Max-heap alternate implementation
	
	/* int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> mset(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            mset.erase(mset.begin());
        }
        return *mset.begin();
    } */
	// quick select
	
	
	
	// nth_element 
    /* int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    } */


	// Partial sort
	/* int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    } */
	
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;

    }
        
    int partition(vector<int>& nums, int low, int high){
        int i = low;
        int pivot = nums[high];
        
        for(int j = low; j < high; j++){
            if(nums[j] >= pivot){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        
        return i;
    }
        
    int findKthLargest(vector<int>& nums, int k) {
        int idx; 
        int low = 0;
        int high = nums.size() - 1;
        
        while(1){
            idx = partition(nums,low,high);
            // cout<<idx<<endl;
            if(idx == k-1){
                return nums[idx];
            }
            if(idx < k-1)
                low = idx + 1;
            else
                high = idx - 1;
        }
        return -1;
    }
    
    
};