class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = -1;
        int rmax = -1;
        int ans = 0;
        int lptr = 0;
        int rptr = height.size() - 1;
        while(lptr <= rptr){
            lmax = max(lmax, height[lptr]);
            rmax = max(rmax, height[rptr]);
            if(lmax <= rmax){
                ans += (lmax - height[lptr]);
                lptr++;
            }
            else{
                ans += (rmax - height[rptr]);
                rptr--;
            }
        }
        return ans;
    }
};