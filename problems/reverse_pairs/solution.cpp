class Solution {
public:
    int merge_sort(int l, int r, vector<int>& a) {
        if(l<r) {
            int cnt;
            int m = (l+r)/2;
            
            cnt = merge_sort(l, m, a);
            cnt += merge_sort(m+1, r, a);
            cnt += merge(l, m, r, a);
            
            return cnt;
        }
        else 
            return 0;
    }
    
    int merge(int l, int m, int r, vector<int>& a) {
        int n1 = m-l+1, n2 = r-m;
        int a1[n1], a2[n2];
        
        for(int i=0; i<n1; i++) a1[i] = a[l+i];
        for(int i=0; i<n2; i++) a2[i] = a[m+i+1];
        
        // a1[n1] = INT_MAX, a2[n2] = INT_MAX;
        
        // logic
        int cnt = 0, i = 0, j = 0;
        while(i<n1 && j<n2) {
            if((long)a1[i] > (long)2 * a2[j]) {
                cnt += n1-i;
                j++;
            }
            else {
                i++;
            }
        }
        
        // merging
        i=0, j=0;
        int k = l;
        while(i<n1 && j<n2) {
            if(a1[i]>=a2[j]) {
                a[k] = a2[j];
                j++;
            }
            else {
                a[k] = a1[i];
                i++;
            }
            
            k++;
        }
        
        while(i < n1) {
            a[k] = a1[i];
            k++, i++;
        }
        
        while(j < n2) {
            a[k] = a2[j];
            k++, j++;
        }
        
        return cnt;
    }
        
        
    int reversePairs(vector<int>& nums) {
        return merge_sort(0, nums.size()-1, nums);
    }
};