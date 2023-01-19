
// O(n) time, O(1) space. Modify input array
class Solution {
public:
    int store(vector<int> &nums, int curr){

        while(curr != nums[curr]){
            int prev = nums[curr];
            nums[curr] = curr;
            curr = prev;
        }
        return curr;
    }

    int findDuplicate(vector<int>& nums) {
        return store(nums, 0);    
    }
};

// O(n) time, O(n) space. Modify input array
class Solution {
public:
    int store(vector<int> &nums, int curr){
        if(curr == nums[curr])
            return curr;
        int prev = nums[curr];
        nums[curr] = curr;
        return store(nums, prev);
    }

    int findDuplicate(vector<int>& nums) {
        return store(nums, 0);    
    }
};

//Sort
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};