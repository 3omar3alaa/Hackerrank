class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string val = countAndSay(n-1);
        int count = 0;
        string result;
        for(int i = 0; i < val.length() - 1; i++)
        {
            if(val[i] != val[i+1])
            {
                result += to_string(count + 1);
                result.push_back(val[i]);
                count = 0;    
            }
            else{
                count++;
            }
        }
        result += to_string(count + 1);
        result.push_back(val[val.length() - 1]);
        return result;
    }
};