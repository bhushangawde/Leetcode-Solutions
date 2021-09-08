class Solution {
public:
    typedef pair<int,int> pr;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        unordered_map<int, int> umap;
        
        for(int i = 0 ; i< nums.size(); i++){
            umap[nums[i]]++;
        }
        
        for(auto it = umap.begin(); it!= umap.end(); it++){
            pq.push({it->second, it->first});
            if(pq.size() > k)
                pq.pop();
        }
        
        while(pq.size() > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};