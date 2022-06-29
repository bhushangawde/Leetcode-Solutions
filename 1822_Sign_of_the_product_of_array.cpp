class Solution {
public:
    int arraySign(vector<int>& nums) {
        int numNeg = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0)
                return 0;
            if(nums[i] < 0)
                numNeg++;
        }
        return numNeg%2 ? -1 : 1;
    }
};