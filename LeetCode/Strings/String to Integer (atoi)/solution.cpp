class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        bool positive = true;
        long result = 0;
        
        int i = s.find_first_not_of(' ');
        if(i == -1) return 0;
        
        if(!isdigit(s[i]) && s[i] != '-' && s[i] != '+')
            return 0;
        
        if(s[i] == '-')
        {
            positive = false;
        }
        
        if(s[i] == '+' || s[i] == '-') i++;
        
        while(isdigit(s[i]))
        {
            result = result * 10 + (s[i] - '0');
            if (result > INT_MAX)
                return positive ? INT_MAX : INT_MIN;
            i++;
        }
        
        return positive ? int(result) : int(-result);
    }
};