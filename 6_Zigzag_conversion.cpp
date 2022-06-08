class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(min(numRows, int(s.size())));
        string ans;
        int currRow = 0;
        bool goingDown = true;    
        
        for(auto c : s){
            rows[currRow] += c;
            
            if(goingDown && currRow < rows.size() - 1)
                currRow++;
            else if(!goingDown && currRow > 0)
                currRow--;
            
            if(currRow == rows.size() - 1 || currRow == 0)
                goingDown = !goingDown;
        }
        
        for(auto row : rows){
            ans += row;
        }
        
        return ans; 
    }
};