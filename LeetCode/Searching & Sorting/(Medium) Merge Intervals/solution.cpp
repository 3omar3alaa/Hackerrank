class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // time complexity O(NLog(N)) due to sorting
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            // no overlapping
            if(intervals[i][0] > intervals[i - 1][1] && intervals[i][0] > end){
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }            
            // there is an overlapping
            else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});
        return result;
    }
};