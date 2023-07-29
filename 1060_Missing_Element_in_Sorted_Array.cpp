// Binary Search
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;

        int missing = (nums[right] - nums[left]) - (right - left);

        if(k > missing){
            return nums[right] + k - missing;
        }

        while(left < right - 1){
            int mid = left + (right - left) / 2;
            int missing = (nums[mid] - nums[left]) - (mid - left);

            if(missing < k){
                left = mid;
                k = k - missing;
            }
            else {
                right = mid;
            }
        }
        
        return nums[left] + k;
    }
};

// Linear Search
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            int missedInGap = nums[i] - nums[i - 1] - 1;
            if (missedInGap >= k) {
                return nums[i - 1] + k;
            }
            k = k - missedInGap;
        }
        
        return nums[n - 1] + k;
    }
};