// Using lambda function
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        string ans;

        for(auto n : nums){
            str.push_back(to_string(n));
        }

        sort(str.begin(), str.end(), [&](string a, string b){
            return a + b > b + a;
        });

        for(auto s : str){
            ans += s;
        }
        if(ans[0] == '0')
            return "0";
        return ans;
    }
};


// Solution 1
class Solution {
public:
    static bool compare(string a, string b){
        if(a+b > b+a)
            return true;
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        vector <string> nums1;
        for(int i = 0 ; i< nums.size(); i++){
            nums1.push_back(to_string(nums[i]));
            // cout<<nums1.back()<<endl;
        }
        sort(nums1.begin(),nums1.end(),compare);  
        if(nums1[0] == "0")
            return "0";
        string ans = "";
        for(int i =0; i< nums1.size(); i++){
            // cout<<nums1[i]<<endl;
            ans += nums1[i];
            
        }
        return ans;
    }
};