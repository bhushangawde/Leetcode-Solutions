class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxh;
        vector<vector<int>> ans;
        
        for(int i = 0 ; i < points.size(); i++){
            maxh.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], points[i]});
            
            if(maxh.size()>k)
                maxh.pop();
        }
        
        while(maxh.size() > 0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        
        return ans;
    }
};