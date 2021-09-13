class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // This solution is much faster than my solution
        //Another solution that uses dictionary
        unordered_set<string> dict (wordList.begin(), wordList.end());
        
        // queue to hold the indices of the words in th wordList
        queue<string> q;
        int ladder = 0;
        
        q.push(beginWord);
        while(!q.empty())
        {
            int n = q.size();
            // loop over all queue elements
            for(int i = 0; i < n; i++){
                string word = q.front();
                if(word == endWord) return ++ladder;
                q.pop();

                // change each character in the word and check if exists
                for(int j = 0; j < word.length(); j++){
                    char org_char = word[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        word[j] = c;
                        if(dict.find(word) != dict.end()){
                            dict.erase(word);
                            q.push(word);
                        }
                    }
                    word[j] = org_char;
                }
            }
            ladder++;            
        }
        
        return 0;
        
        /*
        // array of visited words
        // however we could use
        vector<bool> visited (wordList.size(), false);
        
        // queue to hold the indices of the words in th wordList
        queue<string> q;
        int ladder = 0;
        
        q.push(beginWord);
        while(!q.empty())
        {
            int n = q.size();
            // loop over all queue elements
            for(int i = 0; i < n; i++){
                string word = q.front();
                if(word == endWord) return ++ladder;
                q.pop();

                // traverse over all elements in the wordList to make BFS
                for(int i = 0; i < wordList.size(); i++){
                    int diff_count = 0;
                    if(!visited[i]){
                        for(int j = 0; j < word.length(); j++){
                            if(wordList[i][j] != word[j]) diff_count++;
                        }
                    }

                    if(diff_count == 1){
                        q.push(wordList[i]);
                        visited[i] = true;
                    }
                }
            }
            ladder++;            
        }
        
        return 0;   */
    }
};