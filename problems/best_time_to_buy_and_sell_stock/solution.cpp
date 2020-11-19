class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int max_profit = 0;
        int mn = INT_MAX, mx = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            if(mn>arr[i]) mn = mx = arr[i];
            if(mx<arr[i]) mx = arr[i];
            
            max_profit = max(max_profit, mx-mn);
        }
        
        return max_profit;
    }
};