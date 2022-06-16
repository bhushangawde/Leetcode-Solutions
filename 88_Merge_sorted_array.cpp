class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_ptr = m-1;
        int nums2_ptr = n-1;
        int write_ptr = m + n - 1;
            
        while(write_ptr != -1){
            if(nums2_ptr == -1)
                break;
            
            if(nums1_ptr >= 0 && nums1[nums1_ptr] > nums2[nums2_ptr]){
                nums1[write_ptr] = nums1[nums1_ptr];
                nums1_ptr--;
                write_ptr--;
            }
            else {
                nums1[write_ptr] = nums2[nums2_ptr];
                nums2_ptr--;
                write_ptr--;
            }
        }
    }
};