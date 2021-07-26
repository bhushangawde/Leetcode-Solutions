class Solution {
public:
    int calculate(string s) {
        int i = 0;
        int result = 0;
        int num = 0;
        int sign = 1;
        while(i < s.size()){
            char c = s[i];
            if(isdigit(c)){
                num = num * 10 + (c - '0');
                i++;
            }
            else if (c == '-'){
                result += num*sign;
                num = 0;
                sign = -1;
                i++;
            }
            else if (c == '+'){
                result += num*sign;
                num = 0;
                sign = 1;
                i++;
            }
            else if (c == '*'){
                int num2 = 0;
                i++;
                while(!isdigit(s[i]))
                    i++;
                while(isdigit(s[i])){
                    num2 = num2 * 10 + (s[i] - '0');
                    i++;
                }
                num = num*num2*sign;
                sign = 1;
                
            }
            else if (c == '/'){
                int num2 = 0;
                i++;
                while(!isdigit(s[i]))
                    i++;
                while(isdigit(s[i])){
                    num2 = num2 * 10 + (s[i] - '0');
                    i++;
                }
                num = num/num2*sign;
                sign = 1;
            }
            else
                i++;
        }
        result += num*sign;
        return result;
    }
};