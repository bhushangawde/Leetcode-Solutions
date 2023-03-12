// Using stack
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1)
            return 0;
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

// Using two traversals
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1)
            return 0;
        int left = 0;
        int ans = 0;
        int right = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '(')
                left++;
            else{
                right++;
            }
            if(left == right){
                ans = max(ans, 2 * left);
            }
            if(left < right){
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i = s.size() - 1 ; i >= 0; i--){
            if(s[i] == '(')
                left++;
            else{
                right++;
            }
            if(left == right){
                ans = max(ans, 2 * left);
            }
            if(left > right){
                left = 0;
                right = 0;
            }
        }
        return ans;
    }
};