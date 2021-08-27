class Solution {
public:
    string getLCP(string one, string two){
        string result;
        int j = 0;
        for(int i = 0; i < one.length(); i++){
            if(one[i] != two[j]) break;
            result.push_back(one[i]);
            j++;
        }
        return result;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        string prefix = strs[0];
        for(int i = 1; i < strs.size(); i++){
            prefix = getLCP(prefix, strs[i]);
        }
        return prefix;
    }
};