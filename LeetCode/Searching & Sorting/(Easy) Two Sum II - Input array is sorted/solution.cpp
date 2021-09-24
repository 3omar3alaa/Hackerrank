class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Another solution using two pointers 0 ms
        int start = 0;
        int end = numbers.size() - 1;
        while(start <= end){
            if(numbers[start] + numbers[end] == target) return {++start, ++end};
            
            else if(numbers[start] + numbers[end] < target) ++start;
            else --end;
        }
        return {-1, -1};
        /* My solution 4 ms
        unordered_map<int, int> dict;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++){
            if(dict.find(target - numbers[i]) != dict.end()){
                result.push_back(dict[target - numbers[i]]);
                result.push_back(i + 1);
                return result;
            }
            dict[numbers[i]] = i + 1;
        }            
        return result;*/
    }
};