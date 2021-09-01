class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		
        if(k >= nums.size()) k = k % nums.size();
        if(k == 0) return;
		
		reverse(nums, 0, nums.size() - 1);

        reverse(nums, 0, k - 1);

        reverse(nums, k, nums.size() - 1);

		/*
		This solution is slow
		vector<int> result = nums;
        for(int i = 0; i < k; i++)
            nums[i] = result[nums.size() - k + i];
        
        for(int i = 0; i < nums.size() - k; i++)
            nums[i + k] = result[i];  
		*/		
    }
	
	void reverse(vector<int>& nums, int start, int end){
        int temp;
        while(start < end){
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }            
    }
};