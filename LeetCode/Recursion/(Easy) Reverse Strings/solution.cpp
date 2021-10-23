class Solution {
public:
    void reverseString(vector<char>& s) {
        // recursive solution
        reverseStringRecursive(s, 0, s.size() - 1);
        /*char temp;
        for(int i = 0; i < s.size() / 2; i++){
            temp = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = s[i];
            s[i] = temp;
        }*/      
    }
    
    void reverseStringRecursive(vector<char>& s, int start, int end){
        if(start >= end) return;
        reverseStringRecursive(s, start + 1, end - 1);
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        
    }
};