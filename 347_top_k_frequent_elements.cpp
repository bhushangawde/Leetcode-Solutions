// Bucket Sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) 
            return res;
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> cnt;

        for (auto num : nums)
            cnt[num]++;
        
        for (auto kv : cnt) {
            buckets[kv.second].push_back(kv.first);
        }

        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = 0; j < buckets[i].size(); ++j){
                res.push_back(buckets[i][j]);
                if (res.size() == k) 
                    return res;
            }
        }
        return res;
    }
};

// QuickSelect
class Solution {
public:

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int> &arr, int low, int high, unordered_map<int, int> &ump){
        int i = low;
        int pivot = arr[high];

        for(int j = low; j < high; j++){
            if(ump[arr[j]] >= ump[pivot]){
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        vector<int> ans(k);
        for(auto elem : nums)
            ump[elem]++;
        
        vector<int> arr;
        for(auto elem : ump){
            // cout << elem.first << " "<<elem.second << endl;
            arr.push_back(elem.first);
        }

        int low = 0;
        int high = arr.size() - 1;

        while(1){
            int pivotIdx = partition(arr, low, high, ump);
            if(pivotIdx == k-1){
                // for(int i = 0 ; i < k; i++)
                //     ans.push_back(arr[i]);
                copy_n(arr.begin(), k, ans.begin());
                return ans;
            }

            if(pivotIdx < k - 1)
                low = pivotIdx + 1;
            else 
                high = pivotIdx - 1;
        }
  return {};
    }
};

// Priority queue
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        unordered_map<int, int> umap;
        
        for(auto i : nums){
            umap[i]++;
        }
        
        for(auto i : umap){
            pq.push({i.second, i.first});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
};