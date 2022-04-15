/* class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i>=0; i--){
            int val = digits[i] + carry;
            if(val <= 9){
                digits[i] = val;
                return digits;
            }
            else {
                digits[i] = val%10;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
}; */

void plusone(vector<int> &digits)
{
	int n = digits.size();
	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++;
			return;
		}
	}
		digits[0] =1;
		digits.push_back(0);		
}