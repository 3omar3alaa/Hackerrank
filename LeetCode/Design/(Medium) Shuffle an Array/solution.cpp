class Solution {
public:
    vector<int> arr;
    vector<bool> taken;
    Solution(vector<int>& nums) {
        arr = nums;
        taken.resize(nums.size());
        fill(taken.begin(), taken.end(), false);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int idx;
        vector<int> temp;
        while(find(taken.begin(), taken.end(), false) != taken.end()){
            idx = rand() % arr.size();
            if(!taken[idx]){
                taken[idx] = true;
                temp.push_back(arr[idx]);
            }
        }
        fill(taken.begin(), taken.end(), false);
        return temp;        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */