class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev_max_prod = nums[0];
        int prev_min_prod = nums[0];
        int curr_max_prod = nums[0];
        // if single element in the array
        int ans = nums[0];
        int curr_min_prod;
        
        for(int i=1; i<(int)nums.size(); i++) {
            curr_max_prod = max(max(prev_max_prod*nums[i], prev_min_prod*nums[i]), nums[i]);
            curr_min_prod = min(min(prev_max_prod*nums[i], prev_min_prod*nums[i]), nums[i]);
            ans = max(ans, curr_max_prod);
            
            prev_max_prod = curr_max_prod;
            prev_min_prod = curr_min_prod;
        }
        
        return ans;
    }
};