class Solution {
public:

	// Checking only half number. No need of long datatype
	bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        
        long ans = 0;
        
        while(x > ans){
            
            ans = ans * 10 + x % 10;
            x = x/10;
            cout << ans << "   " << x << endl;
        }
        return (x == ans || x == ans/10 );
    }
	

	// Using long datatype and creating the reverse number completely.
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        long ans = 0;
        int x_orig = x;
        
        while(x > 0){
            // cout << ans << endl;
            ans = ans * 10 + x % 10;
            x = x/10;
        }
        if(ans == x_orig)
            return true;
        return false;
    }
};