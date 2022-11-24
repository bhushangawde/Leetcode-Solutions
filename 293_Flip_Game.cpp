class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        if(currentState.size() < 2)
            return {};
        vector<string> ans;
        int size = currentState.size();
        for(int i = 1; i < size; i++){
            if(currentState[i - 1] == '+' && currentState[i] == '+'){
                currentState[i - 1] = '-';
                currentState[i] = '-';
                ans.push_back(currentState);
                currentState[i - 1] = '+';
                currentState[i] = '+';
            }
        }
        // if(currentState[0] == '+' && currentState[size - 1] == '+'){
        //         currentState[size - 1] = '-';
        //         currentState[0] = '-';
        //         ans.push_back(currentState);
        //         currentState[size - 1] = '+';
        //         currentState[0] = '+';
        // }
        return ans;
    }
};