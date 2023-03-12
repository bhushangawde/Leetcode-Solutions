class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push('x');
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else {
                switch(s[i]){
                    case ')': 
                        if(st.top() == '('){
                            st.pop(); continue;
                        }
                        else
                            return false;
                        break;
                    case ']':
                        if(st.top() == '['){
                            st.pop(); continue;
                        }
                        else
                            return false;
                        break;
                    case '}':
                        if(st.top() == '{'){
                            st.pop(); continue;
                        }
                        else
                            return false;
                        break;
                    default:
                        break; 
                }
            }
        }
        if(st.top() == 'x')
            return true;
        return false;
    }
}; 