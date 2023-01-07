// XOR
class Solution {
public:
    int hammingDistance(int x, int y) {
        int x_ = x^y;
        int bits = 0;
        while(x_>0){
            bits += x_ & 1;
            x_ >>=1;
        }
        return bits;
    }
};

// Brian Kernighan's Algorithm for XOR 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int x_ = x^y;
        int bits = 0;
        while(x_ > 0){
            bits += 1;
            x_ = x_ & (x_ - 1) ;
        }
        return bits;
    }
};