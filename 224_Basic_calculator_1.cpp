class Solution {
public:
    int calculate(string s) {
        int i = 0;
        int result = 0;
        stack <int> nums, ops;
        int num = 0;
        int sign = 1;
        while(i < s.size()){
            char c = s[i];
            if(isdigit(c)){
                num = num * 10 + (c - '0');
                // cout<<num<<endl;
            }
            else {
                
                result = result + num*sign;
                num = 0;
                // cout<<"Res "<<result<<endl;
                if (c == '-'){
                    sign = -1;
                }
                else if (c == '+'){
                    sign = 1;
                }
                else if (c == '('){
                    nums.push(result);
                    ops.push(sign);
                    sign = 1;
                    result = 0;
                }
                else if (c == ')'){
                    result = result * ops.top() + nums.top();
                    nums.pop();
                    ops.pop();
                }
            }
            i++;
        }
        result += num*sign;
        return result;
    }
};