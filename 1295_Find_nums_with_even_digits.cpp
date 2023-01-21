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

// Exploiting constraints
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n,count=0;
        for(int i=0;i<nums.size();i++)
        {
            n=nums[i];
            if(( 10<=n && n<=99) || (1000<=n && n<=9999 ) || ( n==100000 ))
            {
               count++;
            }
        }
        return count;
    }
};