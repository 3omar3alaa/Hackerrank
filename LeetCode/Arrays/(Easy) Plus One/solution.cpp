class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // faster solution
        int rem = 1;
        int idx = digits.size() - 1;
        vector<int> result;
        
        while(idx >= 0){
            digits[idx] += rem;
            rem = digits[idx] / 10;
            result.push_back(digits[idx] % 10);
            idx--;
        }
        if(rem)
            result.push_back(rem);
        
        reverse(result.begin(), result.end());
        return result;
        /*
        4 ms solution
        if((digits[idx] + 1) % 10 == 0){
            rem = 1;
            digits[idx] = 0;
            idx--;
        }
        else{
            digits[idx]++;
        }
        
        while(rem == 1 && idx >= 0){
            if((digits[idx] + 1) % 10 == 0){
                rem = 1;
                digits[idx] = 0;                
            }
            else{
                digits[idx]++;
                rem = 0;
            }
            idx--;
        }
        
        if(idx <= 0 && rem == 1){
            digits.insert(digits.begin(), rem);
        }
        return digits; */    
    }
    
    /*void reverse(vector<int> & nums, int start, int end){
        int temp = 0;
        while(start < end){
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }*/
};