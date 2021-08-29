class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);      
    }
    
    int binarySearch(vector<int>& nums, int target, int start, int end){
        if(start > end) return -1;
        
        int middle = (start + end) / 2;
        if(nums[middle] == target) 
            return middle;
        else if(nums[middle] > target)
            return binarySearch(nums, target, start, middle - 1);
        else
            return binarySearch(nums, target, middle + 1, end);
    }
};