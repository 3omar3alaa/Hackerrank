class Solution {
    struct my_comparator
    {
        // queue elements are vectors so we need to compare those
        bool operator()(std::vector<int> const& a, std::vector<int> const& b) const
        {
            // sanity checks
            assert(a.size() == 3);
            assert(b.size() == 3);

            // reverse sort puts the lowest value at the top    
            return a[2] > b[2];
        }
    };
    
    struct my_comparator_min
    {
        // queue elements are vectors so we need to compare those
        bool operator()(std::vector<int> const& a, std::vector<int> const& b) const
        {
            // sanity checks
            assert(a.size() == 3);
            assert(b.size() == 3);

            // reverse sort puts the lowest value at the top    
            return a[1] < b[1];
        }
    };

    void printVector(vector<vector<int>> v){
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j];
            }
            cout << endl;
        }
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<vector<int>, vector<vector<int>>, my_comparator> seats;
        sort(trips.begin(), trips.end(), my_comparator_min());
        // printVector(trips);
        for(int i = 0; i < trips.size(); i++){
            if(!seats.size() || seats.top()[2] > trips[i][1]){
                if(capacity < trips[i][0]) return false;
                capacity -= trips[i][0];
                seats.push(trips[i]);
            }
            else if(seats.top()[2] <= trips[i][1]){
                // remove all ended trips
                while(seats.size() && seats.top()[2] <= trips[i][1]){
                    capacity += seats.top()[0];
                    seats.pop();
                }
                if(capacity < trips[i][0]) return false;
                capacity -= trips[i][0];
                seats.push(trips[i]);
            }
        }
        return true;
    }
};