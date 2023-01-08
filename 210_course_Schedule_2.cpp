
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