class Solution {
public:
    int minOperations(int n) {
        int ctr = 0;
        int num = n / 2;
        int outp = 0;
        int left = 0 ;
        int right = n-1;
        
        while(ctr< num){
            outp += ((2*right + 1) - (2*left + 1))/2;
            ctr++;
            right--;
            left++;
        }
        return outp;
    }
};