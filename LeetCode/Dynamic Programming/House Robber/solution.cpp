class Solution {
public:
    int rob(vector<int>& nums) {
        /* make an array which holds the max value
        for each value it is either 
        arr[i] = max(nums[i]+arr[i-2], arr[i-1])
        and finally return arr[nums.size() - 1]
        */
        if(nums.size() == 1) return nums[0];
        vector<int> profit (nums.size(), 0);        
        profit[0] = nums[0];
        profit[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        for(int i = 2; i < nums.size(); i++){
            profit[i] = max(nums[i] + profit[i-2], profit[i-1]);
        }
        return profit[nums.size() - 1];
    }
};