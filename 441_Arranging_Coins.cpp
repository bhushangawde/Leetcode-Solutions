//O(LogN)
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;
        while(left <= right){
            long mid = left + (right - left) / 2;
            long currTiles =  mid * (mid + 1) / 2;

            if(currTiles <= n){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};

// O(N)
class Solution {
public:
    int arrangeCoins(int n) {
        long tiles = 0;
        int add = 0;
        int stairs = 0;
        while(tiles <= n){
            add++;
            tiles += add;
        }
        return add - 1;
    }
};