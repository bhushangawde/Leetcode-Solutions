class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, unordered_set<int>> adj;
        for(auto road : roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
        }
        int maxRank = -1;

        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                if(i != j){
                    int currRank = 0;   
                    currRank = adj[i].size() + adj[j].size();
                    if(adj[i].find(j) != adj[i].end()){
                        currRank--;
                    } 
                    maxRank = max(maxRank, currRank);
                }
            }
        }
        return maxRank;
    }
};