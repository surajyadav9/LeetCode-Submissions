class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        int i=0, j=ar.size()-1;
        vector<int> ans;
        
        while(i<j) {
            if(ar[i]+ar[j]==target) {
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(ar[i]+ar[j]<target) i++;
            else j--;
        }
        
        return ans;
    }
};