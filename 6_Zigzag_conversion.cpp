class Solution {
public:


	// O(1) space solution
	string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        string ans;
        int step1, step2, pos;
        for(int i = 0; i < numRows; i++){
            step1 = (numRows - i - 1)*2;
            step2 = i*2;
            pos = i;
            if(pos < s.size())
                ans += s[pos];
            while(true){
                pos += step1; 
                if(pos >= s.size())
                    break;
                if(step1)
                    ans += s[pos];
                
                
                pos += step2;
                if(pos >= s.size())
                    break;
                if(step2)
                    ans += s[pos];
            }    
        }
        return ans; 
    }
	
	// O(n) space solution
    /* string convert(string s, int numRows) {
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
    } */
};