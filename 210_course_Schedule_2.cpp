class Solution {
public:
    
    bool checkCycle(vector <int> graph[], int v, bool *vis, bool *rec, stack<int> &st){
        // cout<<"Entering cycle "<<v <<endl;
    
            vis[v] = true;
            rec[v] = true;
            
            for(int i =0; i < graph[v].size(); i++){
                // cout<<"Entering adjacent "<< i <<endl;
                if(!vis[graph[v][i]] && checkCycle(graph, graph[v][i], vis, rec, st)){
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
        // cout<<v<<" Push stack "<<v<<endl;
        st.push(v);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> ans;
        bool visited[numCourses];
        bool recStack[numCourses];
        stack<int> st;
        for(int i = 0; i< numCourses; i++){
            visited[i] = false;
            recStack[i] = false;
        }
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && checkCycle(graph,i, visited, recStack, st)){
                return ans;
            }
        }    
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};