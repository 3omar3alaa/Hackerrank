class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        /*for(int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;*/
        
        // Another solution - Two Pointer Technique
        int left = 0;
        int right = nums.size() - 1;
        vector<int> result (nums.size());
        for(int i = nums.size() - 1; i >= 0; i--){
            int square;
            if(abs(nums[left]) < abs(nums[right])){
                square = nums[right];
                right--;                
            }
            else{
                square = nums[left];
                left++;
            }                
            result[i] = square * square;
        }
        return result;
    }
};