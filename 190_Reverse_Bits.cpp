// Simple change to make readable
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0 ; i < 32; i++){
            ans = ans << 1;
            ans = ans | (n & 1);
            n = n >> 1;
        }
        return ans;
    }
};


// Solution 1
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0 ; i < 31; i++){
            ans = ans | (n & 1);
            n = n >> 1;
            ans = ans << 1;
        }
        return ans | (n & 1);
    }
};