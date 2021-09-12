class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(N) time complexity solution
        // O(1) space complexity 
        vector<int> result(nums.size(), 1);
        
        // result vector will contain the products of all left numbers
        for(int i = 1; i < nums.size(); i++){
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // variable to hold the result of the right number products
        int right = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            result[i] *= right;
            right *= nums[i];
        }
        
        return result;
        // O(N) time and space complexity solution
        /*vector<int> left (nums.size(), 1);
        vector<int> right (nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++){
            left[i] = left[i - 1] * nums[i - 1];
        }       
        
        for(int i = nums.size() - 2; i >= 0; i--){
            right[i] = right[i + 1] * nums[i + 1];
            
        }
        vector<int> result (nums.size(), 1);
        
        for(int i = 0; i < nums.size(); i++){
            result[i] = left[i] * right[i];
        }
        
        return result;*/
    }
};