// Sliding Window
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int size = s.size();
        unordered_map<char, int> freq;
        while(end < size){
            freq[s[end]]++;
            if(freq.size() <= 2){
                ans = max(ans, end - start + 1);
                end++;
            }
            else { 
                while(freq.size() > 2){
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