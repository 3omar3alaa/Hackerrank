class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int k = 1, i = 0, j = 1;
        while(j < nums.size())
        {
            if(nums[i] == nums[j])
            {
                j++;
            }
            else
            {
                i++;
                if(i != j)
                {
                    nums[i] = nums[j];
                    j++;                   
                }
                k++;
            }                
        }        
        return k;
    }
};