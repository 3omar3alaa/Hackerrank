class Solution {
public:
    static bool cmp(pair<vector<int>, double>& a, pair<vector<int>, double>& b)
    {
        return a.second < b.second;
    }
    
    void sortVector(vector<pair<vector<int>, double>>& dict){
        ::sort(dict.begin(), dict.end(), cmp);
        /*::sort(dict.begin(), dict.end(), [&](auto& a, auto&b){
            return a.second < b.second;
        });*/
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        if(points.size() == 0) return result;
        vector<pair<vector<int>, double>> dict;
        for(vector<int> p : points){
            dict.push_back(make_pair(p, sqrt(pow(p[0], 2) + pow(p[1], 2))));
        }
        sortVector(dict);
        for(int i = 0; i < k; i++){
            result.push_back(dict[i].first);
        }
        return result;        
    }
};