class Solution {
public:
    
    bool checkCycle(vector <int> graph[], int v, bool *vis, bool *rec){
        // cout<<"Entering cycle "<<v <<endl;
    
            vis[v] = true;
            rec[v] = true;
            
            for(int i =0; i < graph[v].size(); i++){
                // cout<<"Entering adjacent "<< i <<endl;
                if(!vis[graph[v][i]] && checkCycle(graph, graph[v][i], vis, rec)){
                    // cout<<"first condition returns true"<<endl;
                    return true;
                }
                else if (rec[graph[v][i]]){
                    // cout<<"Recstack returns true"<<endl;
                    return true;
                }
            }    
        
        rec[v] = false;
        // cout<<v<<" Rec "<<rec[v]<<endl;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        bool visited[numCourses];
        bool recStack[numCourses];
        for(int i = 0; i< numCourses; i++){
            visited[i] = false;
            recStack[i] = false;
        }
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
//         for(int i = 0; i< numCourses ; i++){
//             for(int j =0; j< graph[i].size(); j++){
//                 cout<<i << " " << " " <<graph[i][j]<<endl;
//             }
//             cout<<" Done"<<endl;
//         }
        
        
        
        for(int i = 0; i < numCourses; i++){
            if(checkCycle(graph,i, visited, recStack)){
                // for(int i = 0; i< numCourses ; i++){
                //     cout<<"RecSTACK"<<" "<<recStack[i]<<endl;
                // }
                return false;
            }
        }    
        
        return true;
    }
};