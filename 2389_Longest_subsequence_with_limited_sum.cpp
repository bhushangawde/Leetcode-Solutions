// Sort + Prefix Sum + Upper Bound
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer;
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i = 1 ; i < nums.size(); i++)
            nums[i] += nums[i-1];
        
        for(int i = 0 ; i < queries.size(); i++){
            int pos = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            answer.push_back(pos);
        }  
        return answer;
    }
};

// O(n2) better solution
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer;
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i = 1 ; i < nums.size(); i++)
            nums[i] += nums[i-1];
        
        for(int i = 0 ; i < queries.size(); i++){
            int j;
            for(j = 0; j < nums.size(); j++){
                if(queries[i] < nums[j])
                    break;
            }
            answer.push_back(j);
        }  
        return answer;
    }
};

// O(n2)
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer;
        int count;
        int sum;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < queries.size(); i++){
            count = 0;
            sum = 0;
            int j;
            for(j = 0; j < nums.size(); j++){
                sum += nums[j];
                count += 1;
                if(sum > queries[i]){
                    break;
                }
            }
            if(j == nums.size())
                answer.push_back(count);
            else
                answer.push_back(count - 1);
        }  
        return answer;
    }
};