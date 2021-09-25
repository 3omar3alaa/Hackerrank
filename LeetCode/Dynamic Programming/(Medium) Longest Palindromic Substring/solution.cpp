class Solution {
public:
    string longestPalindrome(string s) {
        // dynamic programming with a very bad performance is time and space
        int start = 0;
        int max_length = 1;
        vector<vector<bool>> table (s.length(), vector<bool>(s.length()));
        
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                table[i][j] = false;
            }
        }
        
        for(int i = 0; i < s.length(); i++)
            table[i][i] = true;
        
        // check if substring has length of two
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == s[i + 1]){
                start = i;
                max_length = 2;
                table[i][i + 1] = true;
            }
        }
        
        // check if substring has length greater than two
        for(int i = 3; i <= s.length(); i++){
            for(int j = 0; j < s.length() - i + 1; j++){
                // get ending index of substring
                int k = i + j - 1;
                
                if(table[j + 1][k - 1] && s[j] == s[k]){
                    table[j][k] = true;
                    
                    if(i > max_length){
                        start = j;
                        max_length = i;
                    }
                }
            }
        }
        
        return s.substr(start, max_length);        
    }
};