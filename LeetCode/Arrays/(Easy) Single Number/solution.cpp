class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
            result ^= nums[i]; // XOR
        return result;
        /*
        Slow solution
        if(nums.size() == 1) return  nums[0];
        
        sort(nums.begin(), nums.end());
        int count = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] != nums[i + 1] && count < 2){
                return nums[i];
            }
            else if(nums[i] == nums[i + 1]){
                count++;
            }
            else{
                count = 1;
            }
        }
        return nums[nums.size() - 1];
        */
    }
};