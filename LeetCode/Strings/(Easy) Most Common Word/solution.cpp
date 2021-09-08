class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Another faster solution
        unordered_map<string,int> mp;
        int len = paragraph.length();
        for(int i = 0 ; i < len ;){
            string s = "";
            while(i < len && isalpha(paragraph[i]))
                s.push_back(tolower(paragraph[i++]));
            while(i < len && !isalpha(paragraph[i]))
                i++;
            mp[s]++;
        }
        int siz = banned.size();
        for(int i = 0 ; i < siz ; i++)
            mp[banned[i]] = 0;
        string res = "";
        int cnt = 0;
        for(auto s:mp){
            if(s.second > cnt){
                cnt = s.second;
                res = s.first;
            }
        }
        return res;
        /*unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream iss(paragraph);
        string word;
        pair<string, int> res ("", 0);
        while (iss >> word)
            if (ban.find(word) == ban.end() && ++count[word] > res.second)
                res = make_pair(word, count[word]);
        return res.first;*/
    }
};