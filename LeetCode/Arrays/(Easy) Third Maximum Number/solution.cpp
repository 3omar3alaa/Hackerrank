class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // o(n) solution using set
        set<int> maximums;
        for(int num : nums){
            maximums.insert(num);
            if(maximums.size() > 3){
                maximums.erase(*maximums.begin());
            }
        }
        
        return maximums.size() == 3 ? *maximums.begin() : *maximums.rbegin(); 
        /*
        O(nlogn) solution
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return nums[nums.size() - 1];
        int i = nums.size() - 2;
        int count = 2;
        while(count && i >= 0){
            if(nums[i] != nums[i + 1])
                count--;
            i--;
        }   
        return count == 0 ? nums[i + 1] : nums[nums.size() - 1];  */  
    }
};