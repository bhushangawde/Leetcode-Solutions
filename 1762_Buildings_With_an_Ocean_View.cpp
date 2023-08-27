// Using monotonic stack
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> answer;
        stack<int> st;
        for(int i = heights.size() - 1; i >=0; i--){
            if(st.size() == 0){
                answer.push_back(i);
            }
            else if(st.size() > 0 && st.top() < heights[i]){
                while(st.size() > 0 && st.top() < heights[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    answer.push_back(i);
                }
            }
            else {
                continue;
            }
            st.push(heights[i]);
        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};