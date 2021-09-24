class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int start, int end){
        if(start >= end) return -1;
        
        int middle = (start + end) / 2;
        if(nums[middle] == target) return middle;
        int left = binarySearch(nums, target, start, middle);
        int right =  binarySearch(nums, target, middle + 1, end);
        return left > right ? left : right;
    }
    
    int search(vector<int>& nums, int target) {
        /*
        is this a binary search problem ?
        */
        
        // return binarySearch(nums, target, 0, nums.size());
        // Another solution
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
          int mid = start + (end - start) / 2;
          if (nums[mid] == target) return mid;
          else if (nums[mid] >= nums[start]) {
            if (target >= nums[start] && target < nums[mid]) end = mid - 1;
            else start = mid + 1;
          }
          else {
            if (target <= nums[end] && target > nums[mid]) start = mid + 1;
            else end = mid - 1;
          }
        }
        return -1;
    }
};