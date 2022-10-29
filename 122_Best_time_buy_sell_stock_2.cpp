class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int i = 0;
        int size = prices.size();
        int curr_min = prices[0];
        int curr_max = 0;
        
        while(i < size-1){
            while(i+1 < size && prices[i+1] <= prices[i]){
                curr_min = prices[i+1];
                i++;
            }
            if(i != size-1){
                // cout<<"min"<<endl<<curr_min<<endl;
                profit -= curr_min;
                curr_min = 0;
            }
            else
                break;
            
            while(i+1 < size && prices[i+1] >= prices[i]){
                curr_max = prices[i+1];
                // cout<<"max"<<endl<<curr_max<<endl;
                i++;
            }
            profit += curr_max;
            curr_max = 0;
        }
        
        return profit;
    }
};

// Dynamic Programming solution
/* 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> profit(size, 0);
        profit[0] = 0;
        for(int i = 1; i < size; i++){
            profit[i] = max(profit[i-1], profit[i-1] + prices[i] - prices[i-1]);
        }
        return profit[size - 1];
    }
}; */