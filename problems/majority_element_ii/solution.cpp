class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1=-1, num2=-1;
        int cnt1=0,  cnt2=0;
        
        for(int el: nums) {
            if(el==num1)
                cnt1++;
            else if(el==num2)
                cnt2++;
            else if(cnt1==0) 
                num1 = el, cnt1=1;
            else if(cnt2==0) 
                num2 = el, cnt2=1;
            else
                cnt1--, cnt2--;
        }
        
        cnt1 = cnt2 = 0;
        for(int el: nums ) {
            if(el==num1) cnt1++;
            else if(el==num2) cnt2++;
        }
        
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(num1);
        if(cnt2>n/3) ans.push_back(num2);
        
        return ans;
    }
};