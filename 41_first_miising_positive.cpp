class Solution {
public:
    
    void swap (int &a, int &b){
        int temp = a;
        a = b; 
        b = temp;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        int i = 0 ;
        while(i < size){
            if(nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
            else
                i++;
        }
        for(int i = 0 ; i < size; i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return i+1;
    }
};