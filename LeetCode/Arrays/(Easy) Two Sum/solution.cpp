class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> table;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(table.find(target-nums[i]) != table.end()){
                result.push_back(table.at(target-nums[i]));
                result.push_back(i);                
                break;
            }
            table[nums[i]] = i;
        }
        return result;
    }
};