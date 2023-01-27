// Using sorting
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)   
            return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(auto interval : intervals){
            if(interval[0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], interval[1]);
            else
                ans.push_back(interval);
        }
        return ans;
    }
};