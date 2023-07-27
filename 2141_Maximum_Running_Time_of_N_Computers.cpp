// Priority Queue -> TLE
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans = 0;

        priority_queue<int> q;
        for(auto b : batteries)
            q.push(b);
        
        while(q.size() >= n){
            int i = 0;
            vector<int> curr;
            while(i < n){
                curr.push_back(q.top());
                q.pop();
                i++;
            }    
            ans++;
            for(int j = 0; j < curr.size(); j++){
                int x = curr[j] - 1;
                if(x > 0){
                    q.push(x);
                }
            }
        }

        return ans;
    }
};