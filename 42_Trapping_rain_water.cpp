class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size < 3){
            return 0;
        }
        
        int left = 0;
        int right = size-1;
        int lMax = 0;
        int rMax = 0;
        int totalWater = 0;
        
        while(left <= right){
            if(lMax < height[left]){
                lMax = height[left];
            }
            if(rMax < height[right]){
                rMax = height[right];
            }
            
            if(lMax <= rMax){
                totalWater += (lMax - height[left]);
                left++;
            }
            else{
                totalWater += (rMax - height[right]);
                right--;
            }
        }
        return totalWater;
    }
};