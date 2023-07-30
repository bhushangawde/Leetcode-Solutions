// Sliding Window
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int size = fruits.size();
        unordered_map<int, int> freq;

        while(end < size){
            freq[fruits[end]]++;
            if(freq.size() <= 2){
                ans = max(ans, end - start + 1);
                end++;
            }
            else {
                while(freq.size() > 2){
                    freq[fruits[start]]--;
                    if(freq[fruits[start]] == 0){
                        freq.erase(fruits[start]);
                    }
                    start++;
                }
                end++;
            }
        }
        return ans;
    }
}; 