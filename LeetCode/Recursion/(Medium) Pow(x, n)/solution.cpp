class Solution {
public:
    double myPowRec(double x, int n){
        if(n == 0) return 1;
        
        double half = myPowRec(x, n / 2); 
        if(n % 2 == 0) return (half * half); 
        else return (half * half * x);
    }
    double myPow(double x, int n) {        
        if(n < 0) {
            x = 1 / x;
        }
        // straight forward approach
        /*double result = 1;
        for(int i = 0; i < abs(n); i++){
            if(n > 0) result *= x;
            else result *= 1/x;
        }
        return result;*/
        return myPowRec(x, n);
    }
};