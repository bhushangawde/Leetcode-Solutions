// Simple solution
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> ump;
        for(int i = 0 ; i < mat.size(); i++){
            for(int j = 0 ; j < mat[0].size(); j++){
                ump[mat[i][j]] += 1;
            }
        }
        for(auto e : ump){
            if(e.second == mat.size())
                return e.first;
        }
        return -1;
    }
};
