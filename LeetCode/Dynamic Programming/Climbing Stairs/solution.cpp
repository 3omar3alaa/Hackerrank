class Solution {
public:
    int climbStairsDP(int n, int * arr){
        if(arr[n] != 0) return arr[n];
        arr[n] = climbStairsDP(n-1, arr) + climbStairsDP(n - 2, arr);
        return arr[n];
    }
    
    int climbStairs(int n) {
        int* arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 0; i < n + 1; i++){
            if(i == 0 || i == 1)
                arr[i] = 1;
            else
                arr[i] = 0;
        }            
        return climbStairsDP(n, arr);        
    }
};