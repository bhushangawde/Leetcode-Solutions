class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(), candies.end());
        int len = candies.size();
        vector <bool> res;
        for (int i = 0 ; i <  len ; i++){
            // if(candies[i] + extraCandies >= max)
            //     res.push_back(true);
            // else
            //     res.push_back(false);
            (candies[i] + extraCandies >= max) ? res.push_back(true) : res.push_back(false);
        }
        return res;
    }
};