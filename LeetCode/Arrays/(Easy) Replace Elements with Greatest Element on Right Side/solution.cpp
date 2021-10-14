class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxNum = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        for(int i = arr.size() - 2; i >= 0; i--){
            int temp = arr[i];
            arr[i] = maxNum;
            maxNum = max(maxNum, temp);
        }
        return arr;
    }
};