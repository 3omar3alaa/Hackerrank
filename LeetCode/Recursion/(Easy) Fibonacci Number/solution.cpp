class Solution {
private:
    unordered_map<int, int> dict;
public:
    int fib(int n) {
        if(n < 2) return n;
        // Bottom Up
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        for(int i = 2; i <= n; i++){
            result.push_back(result[i - 1] + result[i - 2]);
        }
        return result[n];
        // Top Down Approach
        /*dict[0] = 0;
        dict[1] = 1;
        return fibRecursive(n);*/
    }
    
    int fibRecursive(int n){
        if(n < 2) return n;
        else if(dict.find(n) != dict.end()) return dict[n];
        
        dict[n] = fibRecursive(n - 1) + fibRecursive(n - 2);
        return dict[n];
    }
};