class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // two pointers approach
        // make left search for odd values and right for even variables and then swap
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            while(right > left && nums[right] %2 == 1) right--;
            while(left < right && nums[left] %2 == 0) left ++;
            if(left < right){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                right--;
                left++;
            }
        }
        return nums;
    }
};