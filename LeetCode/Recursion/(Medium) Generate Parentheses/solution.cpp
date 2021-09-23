class Solution {
public:
    void recursion(int open, int close, int n, string s, vector<string>& result){
        if(open == n && close == n){
            result.push_back(s);
        }
        
        if(open < n){
            recursion(open + 1, close, n, s + "(", result);
        }
        
        if(close < open){
            recursion(open, close + 1, n, s + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        recursion(0, 0, n, "", result);
        return result;
    }
};