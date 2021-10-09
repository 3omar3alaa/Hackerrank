class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<double> dict;
        for(int i = 0; i < arr.size(); i++){
            if(dict.find(2*arr[i]) != dict.end() || dict.find(arr[i] / 2.0) != dict.end()) return true;
            dict.insert(arr[i]);
        }            
        return false;
    }
};