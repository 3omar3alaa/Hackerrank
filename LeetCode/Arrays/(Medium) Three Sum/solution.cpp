class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		// My solution - not fast
		// but same as second approach in LeetCode
        vector<vector<int>> result;
        unordered_set<int> table;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            table.clear();
            if(i == 0 || nums[i - 1] != nums[i])
            {
                for(int j = i + 1; j < nums.size(); j++){
                    if(table.find(-nums[i] - nums[j]) != table.end()){
                        result.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                        // to avoid duplicates
                        while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                            j++;
                        }
                    }
                    table.insert(nums[j]);
                }
            }
        }            
        return result;
		
		/*
		Another solution that requires no sorting the array first
		set<vector<int>> res;
        unordered_set<int> dups;
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i)
            if (dups.insert(nums[i]).second) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    int complement = -nums[i] - nums[j];
                    auto it = seen.find(complement);
                    if (it != end(seen) && it->second == i) {
                        vector<int> triplet = {nums[i], nums[j], complement};
                        sort(begin(triplet), end(triplet));
                        res.insert(triplet);
                    }
                    seen[nums[j]] = i;
                }
            }
        return vector<vector<int>>(begin(res), end(res));
		
		*/
    }
};