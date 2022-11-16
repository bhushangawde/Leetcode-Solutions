// Left to right - Towards units place
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();
        int ans = 0;
        for(int i = 0 ; i < size ; i++){
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        }
        return ans;
    }
};

// Right to left - From Units place 
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int size = columnTitle.size();
        int ans = (columnTitle[size - 1] - 'A' + 1);
        int i =  0;
        int power = 1;
        for(i = columnTitle.size() - 2 ; i >= 0 ; i--){
            ans += (columnTitle[i] - 'A' + 1) * pow(26, power);
            power++;
        }
        return ans;
    }
};