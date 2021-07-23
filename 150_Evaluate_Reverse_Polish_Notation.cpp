class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int i = 0;
        st.push(stoi(tokens[i]));
        i++;
        int op1, op2, outp;
        while(i!= tokens.size()){
            if(tokens[i] == "/" || tokens[i] == "*" ||tokens[i] == "+" ||tokens[i] == "-"){
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();
                
                if(tokens[i] == "/"){
                    outp = op1 / op2;
                }
                if(tokens[i] == "*"){
                    outp = op1 * op2;
                }
                if(tokens[i] == "+"){
                    outp = op1 + op2;
                }
                if(tokens[i] == "-"){
                    outp = op1 - op2;
                }
                st.push(outp);
            }
            else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        
        return st.top();    
    }
};