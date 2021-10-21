class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        use extra space (arr of bool or hashmap)
        O(N) space, O(N) time
        
        sort then iterate
        O(1) space, O(n log n) time
        
        modify in place
        O(1) space, O(N) time
        */
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};