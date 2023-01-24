class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] > 0)
            return {};
        vector<vector<int>> ans;
        int size = nums.size();
        for(int i = 0; i < size - 2; i++){
            if(nums[i] > 0)
                return ans;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int s = i + 1;
            int e = size - 1;

            while(s < e){
                int sum = nums[i] + nums[s] + nums[e]; 
                if(sum > 0)
                    e--;
                else if (sum < 0)
                    s++;
                else{
                    ans.push_back({nums[i], nums[s], nums[e]});
                    int startNum = nums[s];
                    int endNum = nums[e];
                    while(s < e && nums[s] == startNum)
                        s++;
                    while(s < e && nums[e] == endNum)
                        e--;
                }
            }
        }
        return ans;
    }
};