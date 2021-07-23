class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i<= n; i++){
            if(i%3 ==0 && i%5 ==0)
                ans.push_back("FizzBuzz");
            else if (i%3 ==0)
                ans.push_back("Fizz");
            else if (i%5 ==0)
                ans.push_back("Buzz");
            else{
                string s = to_string(i);
                ans.push_back(s);
            }
        }
        return ans;
    }
};


// Helper for conversion to string
	/* string help(int n)
		{
        string str;
        while(n>0)
        {
            int a=n%10;
            n=n/10;
            a=a+48;
            char ch=a;
            str+=ch;
        }
        reverse(str.begin(), str.end());
        return str;
    } */
	
	
	
/* class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 1;i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for(int i = 2;i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4;i < n; i += 5) {
            res[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
    }
}; */