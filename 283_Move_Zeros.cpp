class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0 || nums.size() ==1)
            return;
        int i = 0;
        int k = 0;
        while(i<nums.size()){
            if(nums[i] != 0 ){
                nums[k] = nums[i];
                i++;
                k++;
            }
            else{
                i++;
            }
        }
        while(k<nums.size()){
            nums[k] = 0;
            k++;
        }
    }
    
};