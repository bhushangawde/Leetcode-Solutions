class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        for(int i = num.size() - 1; i>=0; i--){
            int sum = num[i] + k;
            num[i] = sum % 10;
            k = sum / 10;
            if(k <= 0){
                return num;
            }
        }
        
        while(k > 0){
            num.insert(num.begin(), k%10);
            k = k / 10;
        }
        
        return num;
    }
};