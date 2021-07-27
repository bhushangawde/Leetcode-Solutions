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