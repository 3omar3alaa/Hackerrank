class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // simpler solution
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
        /*if(nums.size() == 0)
            return 0;
        int k = 0, i = 0, j = 0;
        while(i < nums.size() && j < nums.size())
        {
            if(nums[j] == val)
            {
                while(j < nums.size() && nums[j] == val) j++;
                if(j != nums.size()){
                    nums[i] = nums[j];
                    k++;
                    j++;
                    i++;
                }
            }
            else{
                if(i != j) nums[i] = nums[j];
                j++;
                k++;
                i++;
            }
        }        
        return k;*/
    }
};