class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second < b.second;
    }
    
    vector<pair<int, int>> sort(unordered_map<int, int>& dict){
        // Declare vector of pairs
        vector<pair<int, int>> A;

        // Copy key-value pair from Map
        // to vector of pairs
        for (auto& it : dict) {
            A.push_back(it);
        }

        // Sort using comparator function
        ::sort(A.begin(), A.end(), cmp);
        /*::sort(A.begin(), A.end(), [&](auto& a, auto&b){
            return a.second < b.second;
        });*/
        return A;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> dict;
        for(int i = 0; i < nums.size(); i++){
            dict[nums[i]]++;
        }
        vector<pair<int, int>> A = sort(dict);
        for(int i = A.size() - 1; i >= 0 && k != 0; i--){
            result.push_back(A[i].first);
            k--;
        }
        return result;
    }
};