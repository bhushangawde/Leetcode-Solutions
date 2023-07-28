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