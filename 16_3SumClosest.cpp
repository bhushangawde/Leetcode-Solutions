class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);
        
        for(int i = 0; i < size - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int s = i + 1;
            int e = size - 1;

            while(s < e){
                int currSum = nums[i] + nums[s] + nums[e];
                int currDiff = abs(currSum - target); 

                if (currDiff < minDiff){
                    minDiff = currDiff;
                    closestSum = currSum;
                }
                else if(currSum > target)
                    e--;
                else
                    s++;
            }
        }
        return closestSum;
    }

};