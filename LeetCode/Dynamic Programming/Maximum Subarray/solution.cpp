class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int * arr = new int[nums.size()];
        int max_val = nums[0];
        arr[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            arr[i] = max(nums[i], nums[i] + arr[i-1]);
            max_val = max(max_val, arr[i]);
        }
        return max_val;
    }
};