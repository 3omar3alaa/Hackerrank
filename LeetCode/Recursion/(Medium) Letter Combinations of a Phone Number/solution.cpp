class Solution {
private:
    unordered_map<char, vector<char>> dict = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
    
public:
    void backtrack(int index, string path, string& digits, vector<string>& result){
        if(path.length() == digits.length()){
            result.push_back(path);
            return;
        }
        
        vector<char> arr = this->dict[digits[index]];
        for(char c : arr){
            backtrack(index + 1, path + c, digits, result);
        }
    }
    
    vector<string> letterCombinations(string digits) {        
        vector<string> result;
        if(digits.length() == 0) return result;
        backtrack(0, "", digits, result);
        return result;
    }
};