class Solution {
public:
    int climbStairs(int n) {
        int ar[46];
        ar[0] = 0, ar[1] = 1, ar[2] = 2;
        for(int i=3; i<=n; i++) 
            ar[i] = ar[i-1] + ar[i-2];
        
        return ar[n];
    }
};