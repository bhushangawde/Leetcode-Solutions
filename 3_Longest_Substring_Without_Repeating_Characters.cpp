class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int start = 0;
        int end = 0;
        unordered_map<char, int> ump;
        int answer = 0;
        while(end < size){
            ump[s[end]]++;
            if(ump.size() < end - start + 1){
                ump[s[start]]--;
                if(ump[s[start]] == 0)
                    ump.erase(s[start]);
                
                start++;
                end++;
            }
            else if(ump.size() == end - start + 1) {
                answer = max(answer, end - start + 1);
                end++;
            }
        }
        return answer;
    }
};