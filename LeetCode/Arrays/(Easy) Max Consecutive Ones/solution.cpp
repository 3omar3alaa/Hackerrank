class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]) count++;
            else{
                maxCount = max(maxCount, count);
                count = 0;
            }            
        }
        return max(maxCount, count);
    }
};