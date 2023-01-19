// Hare and tortoise
class Solution {
public:
    
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// O(nlogn) time, O(1) space. Binary Search
class Solution {
public:
    int count(vector<int> &nums, int curr){
        int cnt = 0;
        for(auto elem : nums){
            if(elem <= curr)
                cnt++;
        }
        return cnt;
    }

    int findDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int dup;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(count(nums, mid) > mid){
                dup = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return dup;
    }
};

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