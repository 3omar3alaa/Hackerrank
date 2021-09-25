class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        /*
        O(NLog(N)) solution using priority Queues min heap
        */
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> rooms;
        for(int i = 0; i < intervals.size(); i++){
            if(!rooms.size() || rooms.top() > intervals[i][0]) rooms.push(intervals[i][1]);
            else if(rooms.top() <= intervals[i][0]){
                rooms.pop();
                rooms.push(intervals[i][1]);
            }
        }            
        return rooms.size();        
    }
};