class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (nums.size()*(nums.size() + 1))/2;
        for(int i = 0; i < nums.size(); i++)
            sum-= nums[i];
        return sum;

		/*
		Another faster solution
		sort(arr.begin(),arr.end());
        int i;
        for(i=0;i<arr.size();i++){
            if(i!=arr[i])break;
        }
        return i;		
		*/
    }
};