class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_ = -1;
        int left = 0;
        int right = height.size() - 1;
        
        while(left < right){
            int area = (min(height[right],height[left])*(right - left));
            max_ = max(max_ , area);
            
            if(height[left] <= height[right])
                ++left;
            else
                --right;
        }
        return max_;
    }
};