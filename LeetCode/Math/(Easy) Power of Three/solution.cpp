class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        while(n % 3 == 0)
            n /= 3;
        return n == 1;
        // return isPowerOfThree(double(n));
    }
    
    bool isPowerOfThree(double n) {
        if(n == 1) return true;
        if(n < 1) return false;
        return isPowerOfThree(n / 3);
    }
};