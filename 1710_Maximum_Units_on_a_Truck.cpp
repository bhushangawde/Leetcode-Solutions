// Sorting
class myCompare {
public:
    bool operator()(vector<int> v1, vector<int> v2){
        return v1[1] > v2[1];
    }    
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), myCompare());
        int ans = 0;
        int tSize = truckSize;
        for(int i = 0; i < boxTypes.size() && tSize > 0; i++){
            int boxes = min(boxTypes[i][0] , tSize);
            ans += boxes * boxTypes[i][1];
            tSize -= boxes;
        }
        
        return ans;
    }
};