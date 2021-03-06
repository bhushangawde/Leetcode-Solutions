class Solution {
public:
	// Addition by first CONVERTING TO INTEGERS  
	string addBinary(string a, string b) {
        int aPtr = a.size() - 1;
        int bPtr = b.size() - 1;
        string ans = "";
        int carry = 0;
        
        while(aPtr >= 0  || bPtr >= 0){
            int val1 = aPtr>=0 ? a[aPtr--] - '0' : 0;
            int val2 = bPtr>=0 ? b[bPtr--] - '0' : 0;
            int sum = val1 + val2 + carry;
            carry = sum > 1 ? 1 : 0;
            ans += to_string(sum % 2);
        }
        if(carry == 1)
            ans += "1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
	
	// Addition using strings 
    string addBinary(string a, string b) {
        string carry = "0";
        int len1 = a.size();
        int len2 = b.size();
        if(len1 > len2){
            int diff = len1 - len2;
            for(int i = 0 ; i < diff; i++)
                b = "0" + b;
        }
        else if (len2 > len1){
            int diff = len2 - len1;
            for(int i = 0 ; i < diff; i++)
                a = "0" + a;
        }
        
        int aPtr = a.size() - 1;
        int bPtr = b.size() - 1;
        string ans = "";
        
        while(aPtr >= 0  && bPtr >= 0){
            if(a[aPtr] == '1' && b[bPtr] == '1'){
                if(carry == "0"){
                    ans = "0" + ans;
                    carry = "1";
                }
                else if(carry == "1"){
                    ans = "1" + ans;
                    carry = "1";
                }
            }
            else if((a[aPtr] == '1' && b[bPtr] == '0')|| (a[aPtr] == '0' && b[bPtr] == '1')) {
                if(carry == "0"){
                    ans = "1" + ans;
                }
                else if(carry == "1"){
                    ans = "0" + ans;
                }
            }
            else if(a[aPtr] == '0' && b[bPtr] == '0'){
                ans = carry + ans;
                carry = "0";
            }
            aPtr--;
            bPtr--;
        }
        if(carry == "1")
            ans = carry + ans;
        return ans;
    }
};