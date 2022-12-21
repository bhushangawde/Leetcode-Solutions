// BFS solution
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;
        vector<bool> vis(n + 1, false);
        vector<int> color(n + 1, 0);
        for(int i = 0; i < dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<int> bfs;
        for(int i = 1 ; i <= n; i++){
            if(!vis[i]){
                bfs.push(i);
                color[i] = 1;
                while(!bfs.empty()){
                    int node = bfs.front();
                    bfs.pop();
                    for(auto elem : adj[node]){
                        if(!vis[elem]){
                            vis[elem] = true;
                            color[elem] = color[node]*(-1);
                            bfs.push(elem);
                        }
                        else{
                            if(color[elem] == color[node]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
