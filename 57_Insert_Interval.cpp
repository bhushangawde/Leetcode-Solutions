class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        int i = 0; 
        int mergeStart = -1;
        int mergeEnd = -1;
        vector<vector<int>> ans;

        if(intervals.size() == 0){
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval[0] > intervals[size-1][1]){
            ans = intervals;
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval[1] < intervals[0][0]){
            ans.push_back(newInterval);
            for(auto e : intervals)
                ans.push_back(e);
            return ans;
        }

        while(i < size && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        mergeStart = i;
        while(i < size && intervals[i][0] <= newInterval[1]){
            i++;
        }
        mergeEnd = i-1;
        int start = min(newInterval[0], intervals[mergeStart][0]);
        int end = max(newInterval[1], intervals[mergeEnd][1]);

        ans.push_back({start, end});

        while(i < size){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};