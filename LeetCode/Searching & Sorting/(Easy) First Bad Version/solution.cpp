// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return firstBadVersion(1, n);        
    }
    
    int firstBadVersion(int start, int end){
        if(start >= end) return start;
        
        int middle = start + (end - start) / 2;
        if(!isBadVersion(middle))
            return firstBadVersion(middle + 1, end);
        else
            return firstBadVersion(start, middle);
    }
};