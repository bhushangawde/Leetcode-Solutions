
// Straightforward
class Solution {
public:
    string removeDigit(string number, char digit) {
        int maxDiff = 0;
        int pos = -1;
        int size = number.size();
        for(int i = 0 ; i < size - 1; i++){
            if(number[i] == digit && number[i + 1] > digit){
                pos = i;
                break;
            }
        }

        if(pos == -1){
            for(int i = size - 1; i >= 0; i--){
                if(number[i] == digit){
                    pos = i;
                    break;
                }
            }
        }
        
        string answer = "";
        for(int i = 0; i < size; i++){
            if(i == pos)
                continue;
            
            answer += number[i];
        }

        return answer;
    }
};