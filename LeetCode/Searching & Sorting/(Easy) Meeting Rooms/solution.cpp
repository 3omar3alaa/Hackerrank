class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        /*
        loop over the vectors and check if the start time of a meeting is before the
        end of another meeting
        */
        
        if(!intervals.size()) return true;
        
        // O(N2) solution
        /*for(int i = 0; i < intervals.size() - 1; i++){
            for(int j = i + 1; j < intervals.size(); j++){
                if(min(intervals[i][1],intervals[j][1]) > max(intervals[i][0],intervals[j][0]))
                    return false;                
            }
        }*/
        
        // O(N) solution : Sorting
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i - 1][1] > intervals[i][0])
                return false;
        }
        return true;
    }
};