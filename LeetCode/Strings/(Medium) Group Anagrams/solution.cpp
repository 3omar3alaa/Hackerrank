class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // making the sorted string be the hahsmap key
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            vector<int> count (26,0);
            string key = "";
            key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }
        
        for(auto& word : mp){
            result.push_back(word.second);
        }
        return result;
        /*
        Making the letter count be the hashmap key
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            vector<int> count (26,0);
            for(int j = 0; j < strs[i].length(); j++){
                count[(strs[i][j] - 'a')]++;                
            }
            string key = "";
            for(int k = 0; k < 26; k++){
                key.push_back(count[k]);
            }
            mp[key].push_back(strs[i]);
        }
        
        for(auto& word : mp){
            result.push_back(word.second);
        }
        return result;
        */
    }
};