class Solution {
public:
    int maxSubArrayDandQ(vector<int>& nums, int l, int r){
        if(l > r)
            return INT_MIN;
        if(l == r)
            return nums[l];

        int mid = l + (r-l)/2;
        int lsum = 0, rsum = 0;
        int curSumL = 0, curSumR = 0;
        int sum = 0;
        for(int i = mid - 1; i >= l; i--){
            sum += nums[i];
            curSumL = max(sum, curSumL);
        }
        sum = 0;
        for(int i = mid + 1; i <= r; i++){
            sum += nums[i];
            curSumR = max(sum, curSumR);
        }

        return max(max(maxSubArrayDandQ(nums, l, mid - 1), maxSubArrayDandQ(nums, mid+1, r)), curSumL + curSumR + nums[mid]);
    }

    int maxSubArray(vector<int>& nums) {
        // int currSum = 0;
        // int currMax = INT_MIN;
        // for(int i = 0 ; i < nums.size(); i++){
        //     currSum += nums[i];
        //     currMax = max(currMax, currSum);
        //     if(currSum < 0)
        //         currSum = 0;
        // }
        // return currMax;

        return maxSubArrayDandQ(nums, 0, nums.size() - 1);
    }
};