class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows == 1)
            return ans;
        ans.push_back({1, 1});
        if(numRows == 2)
            return ans;
        for(int i = 2; i < numRows ; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j < i; j++){
                int sum = ans[i-1][j] + ans[i-1][j-1];
                row.push_back(sum);
            }
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};