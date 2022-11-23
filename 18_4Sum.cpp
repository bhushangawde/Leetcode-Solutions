class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int size = nums.size();
        if(size < 4)
            return ans;
        
        sort(nums.begin(), nums.end());
        long long sum;
        for(int num1 = 0; num1 < size - 3; num1++){
            if(num1 > 0 && nums[num1] == nums[num1 - 1])
                continue;
            for(int num2 = num1+1; num2 < size - 2; num2++){
                if(num2 > num1 + 1 && nums[num2] == nums[num2 - 1])
                    continue;
                int s = num2 + 1;
                int e = size - 1;
                while(s < e){
                    sum = long(nums[num1]) + long(nums[num2]) + long(nums[s]) + long(nums[e]);
                    if(sum < target)
                        s++;
                    else if(sum > target)
                        e--;
                    else {
                        ans.push_back({nums[num1], nums[num2], nums[s], nums[e]});
                        int first = nums[s];
                        while(s < e && first == nums[s])
                            s++;
                        int last = nums[e];
                        while(s < e && last == nums[e])
                            e--;
                    }
                }
            }
        }
        return ans;
    }
};