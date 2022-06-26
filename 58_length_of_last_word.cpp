class Solution {
public:
	
	// One loop solution
	int lengthOfLastWord(string s) {
        int len = s.size();
        int itr = len - 1;
        int ans = 0;
        while(itr >=0){
            if(s[itr] != ' ')
                ans++;
            else if(ans > 0)
                return ans;
            itr--;
        }
        return ans;
    }
	
	// Two loops solution
    int lengthOfLastWord(string s) {
        int len = s.size();
        int itr = len - 1;
        int ans = 0;
        while(s[itr] == ' '){
            itr--;
        }
        while(itr >= 0 && s[itr] != ' '){
            ans++;
            itr--;
        }
        return ans;
    }
};