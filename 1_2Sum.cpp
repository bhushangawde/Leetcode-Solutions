class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> out;
        int i = 0; 
        while(i < nums.size()){
            int num = target - nums[i];
            if(mp.find(num)!= mp.end()){
                out.push_back(mp[num]);
                out.push_back(i);
            }
            mp[nums[i]] = i;
            i++;
        }
        return out;
    }
};