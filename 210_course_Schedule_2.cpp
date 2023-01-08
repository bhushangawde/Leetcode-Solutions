// BFS solution
class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for(int i = 0 ; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            cnt++;
            ans.push_back(v);

            for(auto node : adjList[v]){
                if(--indegree[node] == 0){
                    q.push(node);
                }
            }    
        }
        if(cnt == numCourses)
            return ans;
        return {};
    }
};

// DFS solution
class Solution {
public:

    bool checkCycle(int node, bool visited[], vector<int> adjList[], bool recStack[], stack<int> &st){
        visited[node] = true;
        recStack[node] = true;

        for(auto a : adjList[node]){
            if(!visited[a] && checkCycle(a, visited, adjList, recStack, st)){
                return true;
            }
            else if(recStack[a]){
                return true;
            }
        }
        recStack[node] = false;
        st.push(node);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        bool recStack[numCourses];
        bool visited[numCourses];
        stack<int> st;
        vector<int> ans;

        for(int i = 0; i < numCourses; i++){
            visited[i] = false;
            recStack[i] = false;
        }

        for(int i = 0; i < prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0 ; i < numCourses; i++){
            if(!visited[i] && checkCycle(i, visited, adjList, recStack, st)){
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