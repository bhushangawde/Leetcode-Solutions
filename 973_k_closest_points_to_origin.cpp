// Using Priority Queue max heapcheck
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int,int>>> pq;

        for(int i = 0 ; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            pq.push({x*x + y*y, {x, y}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(pq.size() > 0){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};  

class Solution {
public:
    
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         priority_queue<pair<int,vector<int>>> maxh;
//         vector<vector<int>> ans;
        
//         for(int i = 0 ; i < points.size(); i++){
//             maxh.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], points[i]});
            
//             if(maxh.size() > k)
//                 maxh.pop();
//         }
        
//         while(maxh.size() > 0){
//             ans.push_back(maxh.top().second);
//             maxh.pop();
//         }
        
//         return ans;
//     }
    
	
	// QUICKSELECT IMPLEMENTATION
    int distance(int x, int y){
        return x*x + y*y;
    }
    
    int partition(vector<vector<int>>& points, int low, int high, int k){
        int idx = low;
        int pivot = distance(points[high][0],points[high][1]);
        
        for(int j = low; j < high; j++){
            if(distance(points[j][0], points[j][1]) < pivot){
                swap(points[idx], points[j]);
                idx++;
            }
        }
        swap(points[idx], points[high]);
        
        return idx;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        int low = 0;
        int high = points.size() - 1;
        int mid;
        
        while(low <= high){
            mid = partition(points, low, high, k);
            if(mid == k)
                break;
            if(mid < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};