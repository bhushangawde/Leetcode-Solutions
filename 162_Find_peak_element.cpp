class Solution {
public:
    
	// Iterative 
	int binarySearch(vector<int>& nums, int l, int r){
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[mid+1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
	
	// Recursive
    int binarySearchRec(vector<int>& nums, int l, int r){
        
        if(l == r)
            return l;
        
        int mid = l + (r-l)/2;
        if( mid != nums.size()-1 && nums[mid] > nums[mid+1])
            return binarySearch(nums,l,mid);
        return binarySearch(nums, mid+1, r);
        
    }
    
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size()-1);
		//return binarySearchRec(nums, 0, nums.size()-1);
    }
};