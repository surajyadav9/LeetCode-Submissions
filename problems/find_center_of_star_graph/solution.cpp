class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ar[100005];
        memset(ar, 0, sizeof(ar));
        
        for(auto p: edges) {
            ar[p[0]]++;
            ar[p[1]]++;
        }
        
        for(int i=0; i<100005; i++) 
            if(ar[i]>1)
                return i;
        
        return 0;
    }
};