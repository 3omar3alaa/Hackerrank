class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // two pointers approach
        sort(nums.begin(), nums.end());
        int diff = INT_MAX; // hold the difference between number and the target
        for(int i = 0; i < nums.size() && diff != 0; i++){
            if(i == 0 || nums[i - 1] != nums[i]){
                int right = nums.size() - 1;
                int left = i + 1;
                while(left < right){
                    int sum = nums[i] + nums[left] + nums[right];
                    if (abs(target - sum) < abs(diff)) {
                        diff = target - sum;
                    }
                    if(sum < target)
                        left++;
                    else
                        right--;                    
                }
            }
        }        
        return target - diff;        
    }
};