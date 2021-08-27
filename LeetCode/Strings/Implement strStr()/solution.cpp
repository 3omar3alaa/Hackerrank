class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0) return 0;  
        if(haystack.length() == 0) return -1;
        
        int index = -1;
        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[0])
            {
                index = i;
                int temp = i;
                for(int j = 0; j < needle.length(); j++){
                    if(needle[j] != haystack[temp])
                    {
                        index = -1;
                        break;
                    }
                    temp++;
                    if(j == needle.length() - 1) return index;
                }
            }
        }
        return index;
    }
};