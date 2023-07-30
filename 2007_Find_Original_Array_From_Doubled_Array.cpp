// Only Sorting
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 == 1)
            return {};
        int countZero = 0;
        for(auto e : changed){
            if(e == 0){
                countZero++;
            }
        }
        if(countZero % 2 == 1)
            return {};
        
        vector<int> answer;
        sort(changed.begin(), changed.end());
        int id = 0;

        int ansId = 0;
        while(id < changed.size() && changed[id] == 0){
            answer.push_back(0);
            ansId++;
            id += 2;
        }
        if(id >= changed.size())
            return answer;

        answer.push_back(changed[id]);
        int checkFor = 2 * changed[id];
        id++;
        
        while(id < changed.size()){
            while(id < changed.size() && changed[id] != checkFor){
                answer.push_back(changed[id]);
                id++;
            }
            
            id++;
            if(id < changed.size()){
                if(ansId == answer.size() - 1){
                    answer.push_back(changed[id]);
                    checkFor = 2 * changed[id];
                    ansId++;
                    id++;
                }
                else {
                    ansId++;
                    checkFor = 2 * answer[ansId];
                }
            }
        }

        if(answer.size() == (changed.size() / 2))
            return answer;
        
        return {};
    }
};