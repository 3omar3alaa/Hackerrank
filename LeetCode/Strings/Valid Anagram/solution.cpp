class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map <char, int> one;
        unordered_map <char, int> two;
        
        for(int i = 0; i < s.length(); i++){
            one[s[i]]++;
            two[t[i]]++;
        }
        for(pair<char, int> tup : one){
            if(tup.second != two[tup.first]) return false;
            // cout << tup.second << " ";
            // cout << two[tup.first] << endl;
        }
        // cout << one.size() << endl;
        return true;
    }
};