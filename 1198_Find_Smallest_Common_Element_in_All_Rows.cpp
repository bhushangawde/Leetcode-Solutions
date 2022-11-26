// Brute force Simple solution - O(RClogRC)
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

// Cache locality - Optimized O(RClogRC)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> ump;
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i = 0 ; i < cols; i++){
            for(int j = 0 ; j < rows; j++){
                ump[mat[j][i]] += 1;
                if(ump[mat[j][i]] == rows)
                    return mat[j][i];
            }
        }
        return -1;
    }
};
// Replace with int array - (O(RC))
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int ump[10001] = {0};
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i = 0 ; i < cols; i++){
            for(int j = 0 ; j < rows; j++){
                ump[mat[j][i]] += 1;
                if(ump[mat[j][i]] == rows)
                    return mat[j][i];
            }
        }
        return -1;
    }
};

// Binary Search - O(RClogC)
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        for(int j = 0 ; j < cols; j++){
            bool found = true;
            for(int i = 1 ; i < rows; i++){
                found = binary_search(begin(mat[i]), end(mat[i]), mat[0][j]);
                if(!found)
                    break;
            }
            if(found)
                return mat[0][j];
        }
        return -1;
    }
};