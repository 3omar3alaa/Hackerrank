class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        
        // Another solution
        int N = arr.size();
        int i = 0;

        // walk up
        while (i+1 < N && arr[i] < arr[i+1])
            i++;

        // peak can't be first or last
        if (i == 0 || i == N-1)
            return false;

        // walk down
        while (i+1 < N && arr[i] > arr[i+1])
            i++;

        return i == N-1;
        
        /*
        // check if the mountain goes up first
        if(arr[0] > arr[1]) return false;
        bool up = true;
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] == arr[i + 1]) return false;
            
            // going down
            if(up && arr[i] > arr[i + 1]) up = false;
            
            if(!up && arr[i] < arr[i + 1]) return false;
        }
        
        return !up ? true : false;*/
    }
};