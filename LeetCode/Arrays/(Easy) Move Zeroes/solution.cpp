class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[idx] = nums[i];
                idx++;
            }
        }
        while(idx < nums.size()){
            nums[idx] = 0;
            idx++;
        }
        /*
        Slow solution
        if(nums.size() == 1) return;
        int zero_idx = 0;
        int num_idx = 0;
        while(zero_idx < nums.size() && num_idx < nums.size()){            
            while(nums[zero_idx] != 0 && zero_idx < nums.size() - 1) zero_idx++;
            num_idx = zero_idx; 
            while(nums[num_idx] == 0 && num_idx < nums.size() - 1) num_idx++;
            //cout << num_idx << " " << zero_idx << endl;
            if(num_idx > zero_idx && num_idx < nums.size() && zero_idx < nums.size())
                swap(nums[num_idx], nums[zero_idx]);
            num_idx++;
            zero_idx++;
        }*/
    }
};