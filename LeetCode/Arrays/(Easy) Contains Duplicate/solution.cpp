class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1])
                return true;
        }
        return false;
        /*
        Slow solution
        set <int> table;
        for(int i = 0; i < nums.size(); i++){
            if(table.find(nums[i]) != table.end())
                return true;
            table.insert(nums[i]);
        }
        return false;
        */
    }
};