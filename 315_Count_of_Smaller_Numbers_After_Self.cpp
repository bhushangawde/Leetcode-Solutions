class Solution {
public:

    void merge(vector<pair<int, int>>& nums, vector<int>& ans, int left, int mid, int right){
        vector<pair<int, int>> temp;
        int i = left;
        int j = mid + 1;

        while(i <= mid && j <= right){
            if(nums[i].first > nums[j].first){
                temp.push_back(nums[i]);
                ans[nums[i].second] += (right - j + 1);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= right){
            temp.push_back(nums[j]);
            j++;
        }

        for(int l = 0; l < temp.size(); l++){
            nums[left + l] = temp[l];
        }
    }


    void mergeSort(vector<pair<int, int>>& nums, vector<int>& ans, int l, int r){
        if(l < r){
            int mid = l + (r - l) / 2;
            mergeSort(nums, ans, l, mid);
            mergeSort(nums, ans, mid + 1, r);
            merge(nums, ans, l, mid, r);
        }
    }


    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(size, 0);
        vector<pair<int, int>> v;
        for(int i = 0; i < size; i++){
            v.push_back({nums[i], i});
        }

        mergeSort(v, ans, left, right);
        return ans;
    }
};