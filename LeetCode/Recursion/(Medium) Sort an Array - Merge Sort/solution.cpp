class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Merge sort
        /*vector<int> result;
        for(int i = 0; i < 10; i++){
            result.push_back(i);
        }
        vector<int> temp = vector<int>(result.begin() + 4, result.begin() + 8);
        for(int i = 0; i < temp.size(); i++){
            cout << temp[i] << endl;
        }
        return result;*/
        return mergeSort(nums);
    }
    
    vector<int> mergeSort(vector<int>& nums){
        if(nums.size() == 1) return nums;
        
        int medium = nums.size() / 2;
        vector<int> left = vector<int>(nums.begin(), nums.begin() + medium);
        vector<int> right = vector<int>(nums.begin() + medium, nums.end());
        
        vector<int> merged_left = mergeSort(left);
        vector<int> merged_right = mergeSort(right);
        
        return combine(merged_left, merged_right);
    }
    
    vector<int> combine(vector<int>& left, vector<int>& right){
        vector<int> result;
        int i = 0;
        int j = 0;
        while(i < left.size() && j < right.size()){
            if(left[i] < right[j]){
                result.push_back(left[i]);
                i++;
            }
            else{
                result.push_back(right[j]);
                j++;
            }
        }
        if(i == left.size() && j < right.size()){
            while(j < right.size()){
                result.push_back(right[j]);
                j++;
            }
        }
        else if(i < left.size() && j == right.size()){
            while(i < left.size()){
                result.push_back(left[i]);
                i++;
            }
        }
        return result;
    }
};