struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isWord = false;
    string word = "";
};
   

class Solution {
public:
    void DFS(vector<vector<char>>& board, TrieNode* current, vector<vector<bool>>& visited, vector<string>& result, int row, int col){
        // if the order is equal to the coordinates of the board then mark as visited
        if(current -> isWord){
            result.push_back(current -> word);
            current -> isWord = false;
            // return;
        }            

        /*
        must make the cell checked to overcome the case of "C" going back to left value "B" in
         [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
         
         AKA: make it checked
        */
        visited[row][col] = true;
        // bool exists = false;
        
        if(row - 1 >= 0 && current -> children.find(board[row - 1][col]) != current -> children.end() && !visited[row - 1][col]) 
            DFS(board, current -> children[board[row - 1][col]], visited, result, row - 1, col);
        
        if(col - 1 >= 0 && current -> children.find(board[row][col - 1]) != current -> children.end()&& !visited[row][col - 1]) 
            DFS(board, current -> children[board[row][col - 1]], visited, result, row, col - 1);
        
        if(row + 1 < board.size() && current -> children.find(board[row + 1][col]) != current -> children.end() && !visited[row + 1][col]) 
            DFS(board, current -> children[board[row + 1][col]], visited, result, row + 1, col);
        
        if(col + 1 < board[0].size() && current -> children.find(board[row][col + 1]) != current -> children.end() && !visited[row][col + 1]) 
            DFS(board, current -> children[board[row][col + 1]], visited, result, row, col + 1);
        
        /* only mark the cell as visited if the word was found
        else mark it as not visited
        mainly to overcome this problem of marking many "A"s as visited while one of them contains the solution already
        [["C","A","A"],["A","A","A"],["B","C","D"]] "AAB"
        */
        // if(!exists) 
        visited[row][col] = false;
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         /*
        This problem can be solved using Trie
        */
        if(words.size() == 0) return {};
        
        TrieNode* root = new TrieNode();
        
        // make a trie using the provided words
        for(string word: words){
            TrieNode* current = root;
            
            for(char c: word){
                if(current -> children.find(c) == current -> children.end())
                    current -> children[c] = new TrieNode();
                current = current -> children[c];
            }
            current -> isWord = true;
            current -> word = word;
        }
        
        vector<string> result;
        int n = board.size();
        int m = board[0].size();
        // variable to know exactly which letter in the word did we reach
        int order = 0;
        
        /*
        Visited array will have two functionalities
        visited[i][j] = 0 not visited
        visited[i][j] = 1 visited
        */
        vector<vector<bool>> visited (n, vector<bool> (m));
        
        resetVisited(visited);        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(root -> children.find(board[i][j]) != root -> children.end() && !visited[i][j]){
                    DFS(board, root -> children[board[i][j]], visited, result, i, j);
                }
            }
        }
        return result;        
    }
    
    void resetVisited(vector<vector<bool>>& visited){
        int n = visited.size();
        int m = visited[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                visited[i][j] = false;
            }
        }
    }
};