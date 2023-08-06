class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        int firstNum = INT_MAX;
        int secondNum = INT_MAX;

        for(auto n : nums){
            if(n <= firstNum){
                firstNum = n;
            }
            else if(n <= secondNum){
                secondNum = n;
            }
            else {
                return true;
            }
        }
        return false;
    }
};