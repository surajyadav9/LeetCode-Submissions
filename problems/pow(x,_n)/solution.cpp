class Solution {
public:
    double myPow(double x, int n) {
        bool neg = false;
        long long lN = n;
        
        if(n<0) {
            neg = true;
            lN *= -1;
        }
            
        double ans= 1.0;
        while(lN>=1) {
            if(lN%2==1) {
                ans *= x;
            }
            
            x *= x;
            lN /= 2;
        }
        
        if(neg) return 1/ans;
        else return ans;
        
    }
};