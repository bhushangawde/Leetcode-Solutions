class Solution {
public:
    
    int solve(vector<int>& cookies, int k, int id, vector<int>& freq, int remainingCount){
        if(cookies.size() - id < remainingCount){
            return INT_MAX;
        }

        if(id == cookies.size()){
            return *max_element(freq.begin(), freq.end());
        }

        int currFreq = INT_MAX;
        for(int i = 0; i < k; i++){
            if(freq[i] == 0)
                remainingCount--;
            freq[i] += cookies[id];
            int tempFreq = solve(cookies, k, id + 1, freq, remainingCount);
            freq[i] -= cookies[id];
            if(freq[i] == 0)
                remainingCount++;
            currFreq = min(currFreq, tempFreq);
        }

        return currFreq;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> freq(k, 0);
        return solve(cookies, k, 0, freq, k);
    }
};


// Recursion + Backtracking
class Solution {
public:
    
    int solve(vector<int>& cookies, int k, int id, vector<int>& freq){
        if(id == cookies.size()){
            return *max_element(freq.begin(), freq.end());
        }

        int currFreq = INT_MAX;
        for(int i = 0; i < k; i++){
            freq[i] += cookies[id];
            int tempFreq = solve(cookies, k, id + 1, freq);
            freq[i] -= cookies[id];
            currFreq = min(currFreq, tempFreq);
        }

        return currFreq;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> freq(k, 0);
        return solve(cookies, k, 0, freq);
    }
};

// Recursion + Backtracking
class Solution {
public:
    
    int solve(vector<int>& cookies, int k, int id, unordered_map<int, int>& freq){
        if(id == cookies.size()){
            int maxFreq = -1;
            for(auto &m : freq){
                maxFreq = max(maxFreq, m.second);
            }
            return maxFreq;
        }

        int currFreq = INT_MAX;
        for(int i = 0; i < k; i++){
            freq[i] += cookies[id];
            int tempFreq = solve(cookies, k, id + 1, freq);
            freq[i] -= cookies[id];
            currFreq = min(currFreq, tempFreq);
        }

        return currFreq;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        unordered_map<int, int> freq;
        return solve(cookies, k, 0, freq);
    }
};