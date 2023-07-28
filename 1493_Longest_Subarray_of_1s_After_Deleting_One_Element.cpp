class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 1;
        int start = 0;
        int end = 0;
        int ans = 1;
        while(end < nums.size()){
            if(nums[end] == 1){
                ans = max(ans, end - start + 1);
                end++;
            }
            else {
                if(count > 0){
                    ans = max(ans, end - start + 1);
                    count--;
                    end++;
                    
                }
                else if(count == 0){
                    count--;
                    while(count < 0){
                        if(nums[start] == 0){
                            count++;
                        }
                        start++;
                    }
                    end++;
                }
            }
        }
        return ans - 1;
    }
};