class Solution {
public
    int fourSumCount(vectorint& nums1, vectorint& nums2, vectorint& nums3, vectorint& nums4) {
        unordered_mapint, int mp1, mp2;
        int n = nums1.size();
        int ans = 0;

        for(int i = 0 ; i  n; i++){
            for(int j = 0 ; j  n; j++){
                mp1[nums1[i] + nums2[j]]++;
                mp2[nums3[i] + nums4[j]]++;
            }
        }

        for(auto e  mp1){
            int num = -e.first;
            int freq1 = e.second; 
            if(mp2.find(num) != mp2.end()){
                int freq2 = mp2[num];
                ans += freq1freq2;
            }
        }

        return ans;
    }
};