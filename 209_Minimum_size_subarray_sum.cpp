class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int ans = INT_MAX;
        int sum = 0;
        while(end < nums.size()){
            sum += nums[end];
            if(sum < target){
                end++;
            }
            else if(sum >= target){
                while(sum >= target){
                    ans = min(ans, end - start + 1);
                    sum -= nums[start];
                    start++;
                }
                end++;
            }
        }

        return ans != INT_MAX ? ans : 0;
    }
};