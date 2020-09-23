class Solution {
public:
    int maxArea(vector<int>& ar) {
            
        int n = ar.size();
        
        int l = 0, r = n-1;
        int ans=0;
        
        while(l<r) { 
            
            int area = min(ar[l], ar[r]) * (r-l);
            
            ans = max(area, ans);
            
            if(ar[l]<ar[r]) l++;
            else r--;
        }
        
        
        return ans;
    }
};