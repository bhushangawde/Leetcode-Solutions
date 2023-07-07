// Backtracking
class Solution {
public:
    
    int solve(int n, vector<vector<int>>& requests, int idx, vector<int> &indegree){
        if(idx == requests.size()){
            int balance = count(indegree.begin(), indegree.end(), 0);
            return balance == n ? 0 : INT_MIN;
        }
        indegree[requests[idx][1]]++;
        indegree[requests[idx][0]]--;

        int take = 1 + solve(n, requests, idx + 1, indegree);

        indegree[requests[idx][1]]--;
        indegree[requests[idx][0]]++;

        int notTake = solve(n, requests, idx + 1, indegree);

        return max(take, notTake);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        return solve(n, requests, 0, indegree);
    }
};