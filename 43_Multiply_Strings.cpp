// A bit faster due to less accesses to the result array.
class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        string result(size1 + size2, '0');
        int n1, n2;
        for(n1 = size1 - 1; n1 >= 0; n1--){
            int carry = 0;
            for(n2 = size2 - 1; n2 >= 0; n2--){
                int prod = (result[n1 + n2 + 1] - '0') + (num1[n1] - '0') * (num2[n2] - '0') + carry;
                result[n1 + n2 + 1] = prod % 10  + '0';
                carry = prod / 10 ;
            }
            result[n1] += carry;
        }
        for(int i = 0 ; i < size2 + size1; i++){
            if(result[i] != '0'){
                return result.substr(i); 
            }
        }
        return "0";
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        string result(size1 + size2, '0');
        int n1, n2;
        for(n1 = size1 - 1; n1 >= 0; n1--){
            for(n2 = size2 - 1; n2 >= 0; n2--){
                int prod = (result[n1 + n2 + 1] - '0') + (num1[n1] - '0')*(num2[n2] - '0');
                result[n1 + n2 + 1] = prod % 10  + '0';
                result[n1 + n2] += prod / 10 ;
            }
        }
        for(int i = 0 ; i < size2 + size1; i++){
            if(result[i] != '0')
                return result.substr(i); 
        }
        return "0";
    }
};