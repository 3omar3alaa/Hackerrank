class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsertBinary(nums, target, 0, nums.size());    
    }
    
    int searchInsertBinary(vector<int>& nums, int target, int start, int end){
        if(start >= end) return start;
        
        int middle = start + (end - start) / 2;
        if(nums[middle] == target) 
            return middle;
        else if(nums[middle] > target)
            return searchInsertBinary(nums, target, start, middle);
        else
            return searchInsertBinary(nums, target, middle + 1, end);
    }
};