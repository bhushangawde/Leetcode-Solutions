// O(n) solution
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i, pivot;
        for(i = size - 2; i>=0; i--){
            if(nums[i] < nums[i + 1])
                break;
        }

        if(i < 0){
            reverse(nums.begin(), nums.end());
        }
        else {
            pivot = i;
            for(int j = size - 1; j > pivot; j--){
                if(nums[j] > nums[pivot]){
                    swap(nums[j], nums[pivot]);
                    break;
                }
            }

            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};
