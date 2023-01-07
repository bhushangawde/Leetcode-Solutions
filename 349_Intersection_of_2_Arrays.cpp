// Using Freq Maps
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int mp1[1001] = {0};
        int mp2[1001] = {0};
        for(auto e : nums1)
            mp1[e]++;
        for(auto e : nums2)
            mp2[e]++;
        
        vector<int>ans;
        for(int i = 0 ; i < 1001; i++){
            if(mp2[i] > 0 && mp1[i] > 0)
                ans.push_back(i);
        }
        return ans;
    }
};