// Using & operator
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        
        return !(n & (n-1));
    }
};

// Using & ~ operators
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        
        return ((n & (~(n-1))) == n);
    }
};


// Using bit count
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        int cnt = 0;
        while(n > 0){
            if(n & 1 == 1){
                cnt++;
            }
            n = n >> 1;
        }
        return cnt == 1;
    }
};

// Using division operator
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        while(n > 1){
            if(n%2 && n > 1){
                return false;
            }
            n = n / 2;
        }
        return true;
    }
};