class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_day, prev, profit=0;
        
        buy_day = 0;
        prev = prices[0];
        
        for(int i=1; i<n; i++) {
            if(prev <= prices[i]) {
                prev = prices[i];
            }
            else {
                int sell_day = i-1;
                if(buy_day != sell_day){
                    profit += (prices[sell_day] - prices[buy_day]);
                }
                
                prev = prices[i];
                buy_day = i;
            }
        }
        
        if(buy_day < n-1) {
            profit += (prices[n-1] - prices[buy_day]);
        }
        
        return profit;
        
    }
};