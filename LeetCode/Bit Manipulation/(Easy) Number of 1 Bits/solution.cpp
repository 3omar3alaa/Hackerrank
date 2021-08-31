class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // faster solution than the commented solution
        while(n){
            n = n&(n-1);
            count++;
        }
        /*
        while(n){
            count += (n & 1);
            n = n >> 1;
        }*/
        return count;
    }
};