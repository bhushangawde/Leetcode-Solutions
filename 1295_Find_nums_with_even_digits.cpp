// Brute force
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt;
        int total = 0;
        int num; 
        int len = nums.size();
        for(int i = 0 ; i< len; i++){
            cnt = 0;
            num = nums[i];
            while (num > 0){
                num = num/10;
                cnt++;
            }
            
            if(cnt % 2 == 0){
                total++;
            }
        }  
        return total;
    }
};