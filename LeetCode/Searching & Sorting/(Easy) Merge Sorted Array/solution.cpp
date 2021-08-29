class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = m + n - 1;
        while(m != 0 && n != 0)
        {
            if(nums1[m-1] > nums2[n-1])
            {
                nums1[count] = nums1[m-1];
                m--;
            }
            else
            {
                nums1[count] = nums2[n-1];
                n--;
            }
            count--;
        }
        if(m == 0){
            for(int i = n; i > 0; i--){
                nums1[count] = nums2[i - 1];
                count--;
            }            
        }
        else{
             for(int i = m; i > 0; i--){
                nums1[count] = nums1[i - 1];
                count--;
            }  
        }
        
    }
};