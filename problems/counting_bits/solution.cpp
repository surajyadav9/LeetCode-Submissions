class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
       
        res[0] =0;
        if(num>0)
            res[1] = 1;
        for(int i=2;i<=num;i++)
        {
            int ones=0;
            ones+= res[i%2];
            ones += res[i/2];
            
            res[i] = ones;
        }
        
        return res;
    }
};