class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) return false;
        stack<char> valid_stack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') 
                valid_stack.push(s[i]);
            
            else if(s[i] == '}' ){
                if(valid_stack.empty()) return false;
                if(valid_stack.top() != '{')
                    return false;
                valid_stack.pop();
            }
            
            else if(s[i] == ']'){
                if(valid_stack.empty()) return false;
                if(valid_stack.top() != '[')
                    return false;
                valid_stack.pop();
            }
            else if(s[i] == ')'){
                if(valid_stack.empty()) return false;
                if(valid_stack.top() != '(')
                    return false;
                valid_stack.pop();
            }
            
        }
        return valid_stack.empty();
    }
};