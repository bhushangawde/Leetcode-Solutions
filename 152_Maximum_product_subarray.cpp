
// Single Pass
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currProdLeft = 1;
        int currProdRight = 1;
        int maxProd = INT_MIN;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            currProdLeft *= nums[i];
            currProdRight *= nums[n - i - 1];
            maxProd = max(maxProd, max(currProdLeft,currProdRight));
            if(currProdLeft == 0)
                currProdLeft = 1;
            if(currProdRight == 0)
                currProdRight = 1;
        }
        return maxProd;
    }
};

// Two passes
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currProd = 1;
        int maxProd = INT_MIN;
        for(int i = 0 ; i < nums.size(); i++){
            currProd *= nums[i];
            maxProd = max(maxProd, currProd);
            if(currProd == 0)
                currProd = 1;
        }
        currProd = 1;
        for(int i = nums.size() - 1; i>=0; i--){
            currProd *= nums[i];
            maxProd = max(maxProd, currProd);
            if(currProd == 0)
                currProd = 1;
        }
        return maxProd;
    }
};