class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int s: nums) {
            sum+=s;
        }
        
        long long g = goal*1LL;
        long long n = g-sum;
        n = n<0? (n*-1LL) : n;
        
        int ans=0;
        
        if(n%limit>0) {
            ans = n/limit + 1;
        }
        else {
            ans = n/limit;
        }
        
        
        return ans;
    }
};