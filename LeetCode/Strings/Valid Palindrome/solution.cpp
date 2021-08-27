class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0 || s.length() == 1) return true;
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            while(!isalnum(s[i]) && i < s.length()) i++;
            while(!isalnum(s[j]) && j > 0) j--;
            if(i > j) return true;
            if(toupper(s[i]) != toupper(s[j])) return false;            
            i++; j--;
        }
        return true;
    }
};