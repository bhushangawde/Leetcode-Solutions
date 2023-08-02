
// Solution 3
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c = 0;
        while(n > 0) {
            c += (n & 1);
            n >>= 1;
        }
        return c;
    }
};

// Another solution
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t ans = 0;
        while(n){
            if(n & 1)
                ans++;
            n = n >> 1;
        }
        return ans;
    }
};

/* class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int mask = 1;
        for(int i = 0; i < 32; i++){
            if((n & mask) != 0){
                count++;
            }
            if(i<31)
                mask <<= 1;
        }
        return count;
    }
}; */