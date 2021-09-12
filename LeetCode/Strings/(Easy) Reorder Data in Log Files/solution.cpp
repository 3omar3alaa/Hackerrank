class Solution {
public:
    
    static bool customComparator(pair<string, string>& a, pair<string, string>& b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits, result;
        vector<pair<string, string>> letter;
        
        for(string s: logs){
            int i = 0;
            while(s[i] != ' ') i++;
            if(isdigit(s[++i])) digits.push_back(s);
            else letter.push_back({s.substr(0, i), s.substr(i)});
        }
        
        // we should make our own custom comparator
        sort(letter.begin(), letter.end(), [&](auto& a, auto&b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        // sort(letter.begin(), letter.end(), customComparator);
        
        for(pair<string, string> p : letter) result.push_back(p.first + p.second);
        for(string s : digits) result.push_back(s);
        
        return result;
    }    
};