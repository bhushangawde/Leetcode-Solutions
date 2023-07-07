class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int start = 0;
        int end = 0;
        int minC = 0;
        int tc = 0;
        int fc = 0;
        int maxSize = 0;
        while(end < answerKey.size()){
            if(answerKey[end] == 'T')
                tc++;
            else
                fc++;

            minC = min(tc, fc);
            
            if(minC <= k){
                end++;
                maxSize = max(maxSize, end - start);
            }
            else if(minC > k){
                while(minC > k){
                    if(answerKey[start] == 'T')
                        tc--;
                    else
                        fc--;
                    
                    minC = min(tc, fc);
                    start++;
                }
                end++;
            }
        }

        return maxSize;
    }
};