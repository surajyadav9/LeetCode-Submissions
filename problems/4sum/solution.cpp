class Solution {
public:
    
    vector<vector<int>> two_sum(vector<int>& nums, int target, int i, int j, int a, int b)  {
        vector<vector<int>> ans;
        
        while(i<j) {
            if(nums[i]+nums[j]==target) {
                // push ans
                vector<int> temp{a, b, nums[i], nums[j]};
                ans.push_back(temp);
                
                // move both pointer
                i++, j--;
                
                while(i<j && nums[i]==nums[i-1] && nums[j]==nums[j+1]) i++, j--;
            }
            else if(nums[i]+nums[j] < target) i++;
            else j--;
        }
        
        return ans;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // sort the input numbers
        sort(nums.begin(), nums.end());
        
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                // 2 sum problem
                int curr = nums[i] + nums[j];
                vector<vector<int>> temp = two_sum(nums, target-curr, j+1, n-1, nums[i], nums[j]);
                
                // insert result into ans vector
                for(int k=0; k<(int)temp.size(); k++)
                    ans.push_back(temp[k]);
                
                // skip duplicates for 'j'
                while(j<n-2 && nums[j]==nums[j+1]) j++;
            }
            
            // skip duplicates for 'i'
            while(i<n-3 && nums[i]==nums[i+1]) i++;
        }
        
        return ans;
    }
};