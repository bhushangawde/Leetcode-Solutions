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