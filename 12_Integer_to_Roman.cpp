/* class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        if(num/1000 > 0){
            for(int i = 0 ; i < num/1000; i++){
                s += "M";
            }
            num = num % 1000;
        }
        if(num/900 > 0){
            s += "CM";
            num = num % 900;
        }
        
        if(num/500 > 0){
            for(int i = 0 ; i < num/500; i++){
                s += "D";
            }
            num = num % 500;
        }
        if(num/400 > 0){
            s += "CD";
            num = num % 400;
        }
        
        if(num/100 > 0){
            for(int i = 0 ; i < num/100; i++){
                s += "C";
            }
            num = num % 100;
        }
        if(num/90 > 0){
            s += "XC";
            num = num % 90;
        }
        
        if(num/50 > 0){
            for(int i = 0 ; i < num/50; i++){
                s += "L";
            }
            num = num % 50;
        }
        if(num/40 > 0){
            s += "XL";
            num = num % 40;
        }
        
        if(num/10 > 0){
            for(int i = 0 ; i < num/10; i++){
                s += "X";
            }
            num = num % 10;
        }
        if(num/9 > 0){
            s += "IX";
            num = num % 9;
        }
        
        if(num/5 > 0){
            for(int i = 0 ; i < num/5; i++){
                s += "V";
            }
            num = num % 5;
        }
        if(num/4 > 0){
            s += "IV";
            num = num % 4;
        }
        
        if(num > 0){
            for(int i = 0 ; i < num; i++){
                s += "I";
            }
        }
    
        return s;
    }
}; */


class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        for(int i = 0 ; i < 13; i++){
            while(num >= values[i]){
                s += symbols[i];
                num = num - values[i];
            }    
        }
        return s;
    }
};