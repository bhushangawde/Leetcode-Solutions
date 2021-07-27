class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int mp1[1001] = {0}, mp2[1001] = {0};
        vector<int> ans;
        for(int i = 0 ; i< nums1.size(); i++){
            mp1[nums1[i]]++;
        }
        for(int i = 0 ; i< nums2.size(); i++){
            mp2[nums2[i]]++;
        }
        
        for(int i = 0 ; i < 1001; i++){
            if(mp1[i] > 0 && mp2[i] > 0){
                int c = min(mp1[i] , mp2[i]);
                for(int j = 0 ; j < c ; j++)
                    ans.push_back(i);
            }
        }
        
        return ans;
    }
	
	
	// Another Solution
/* 	vector<int> intersect(vector<int>& a, vector<int>& b) {
		unordered_map<int, int> ctr;
		for (int i : a)
			ctr[i]++;
		vector<int> out;
		for (int i : b)
			if (ctr[i]-- > 0)
				out.push_back(i);
		return out;
 	}
	*/
	
	// Yet another solution
	
	/* vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> v;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                v.push_back(nums1[i]);
                i++;j++;
            }
        }
        return v;
    } */
	
	
	
};