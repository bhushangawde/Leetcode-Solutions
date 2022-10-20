// BFS Solution
class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        vector<int> indegree(numCourses, 0);
        queue<int> q;
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

            for(auto node : adjList[v]){
                if(--indegree[node] == 0){
                    q.push(node);
                }
            }    
        }
        return cnt == numCourses;
    }
};

// DFS solution
class Solution {
public:

    bool checkCycle(int node, bool visited[], vector<int> adjList[], bool recStack[]){
        visited[node] = true;
        recStack[node] = true;

        for(auto a : adjList[node]){
            if(!visited[a] && checkCycle(a, visited, adjList, recStack)){
                return true;
            }
            else if(recStack[a]){
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjList[numCourses];
        bool recStack[numCourses];
        bool visited[numCourses];

        for(int i = 0; i < numCourses; i++){
            visited[i] = false;
            recStack[i] = false;
        }

        for(int i = 0; i < prerequisites.size(); i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0 ; i < numCourses; i++){
            if(!visited[i] && checkCycle(i, visited, adjList, recStack)){
                return false;
            }
        }
        return true;
    }
};