// Divisibility by 9
class Solution {
public:
    int addDigits(int num) {
        if(num<=9)
            return num;
        if(num%9 == 0)
            return 9;
        return num%9;
    }
};

// Brute force solution
class Solution {
public:
    int addDigits(int num) {
        int sum;
        while(num>9){
            sum = 0;
            while(num){
                sum += num % 10;
                num = num/10;
            }
            num = sum;
        }
        return num;
    }
};