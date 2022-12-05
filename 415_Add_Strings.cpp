class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        int carry = 0;
        int val;
        while(1){
            if(i1 < 0 && i2 < 0 && carry == 0)
                break;

            int sum = carry;
            if(i1 >= 0){
                sum = sum + (num1[i1] - '0');
                i1--;
            }
            if(i2 >= 0){
                sum = sum + (num2[i2] - '0');
                i2--;
            }
            carry = sum / 10;
            val = sum % 10;
            result += to_string(val);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};