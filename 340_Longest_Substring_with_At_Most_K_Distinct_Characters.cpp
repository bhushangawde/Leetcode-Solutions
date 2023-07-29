// Sliding Window
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int start = 0;
        int end = 0;
        int size = s.size();
        unordered_map<char, int> freq;
        int ans = 0;
        while(end < size){
            freq[s[end]]++;
            if(freq.size() <= k){
                ans = max(ans, end - start + 1);
                end++;
            }
            else {
                while(freq.size() > k){
                    freq[s[start]]--;
                    if(freq[s[start]] == 0){
                        freq.erase(s[start]);
                    }
                    start++;
                }
                end++;
            }
        }
        return ans;
    }
};