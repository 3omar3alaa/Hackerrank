class Solution {
public:
    
    bool DFS(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int order, int row, int col){
        // if the order is equal to the coordinates of the board then mark as visited
        if(order == (word.length() - 1))
            return true;
        
        order++;
        /*
        must make the cell checked to overcome the case of "C" going back to left value "B" in
         [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
         
         AKA: make it checked
        */
        visited[row][col] = true;
        bool exists = false;
        
        if(row - 1 >= 0 && board[row - 1][col] == word[order] && !visited[row - 1][col]) 
            exists |= DFS(board, word, visited, order, row - 1, col);
        
        if(col - 1 >= 0 && board[row][col - 1] == word[order] && !visited[row][col - 1]) 
            exists |= DFS(board, word, visited, order, row, col - 1);
        
        if(row + 1 < board.size() && board[row + 1][col] == word[order] && !visited[row + 1][col]) 
            exists |= DFS(board, word, visited, order, row + 1, col);
        
        if(col + 1 < board[0].size() && board[row][col + 1] == word[order] && !visited[row][col + 1]) 
            exists |= DFS(board, word, visited, order, row, col + 1);
        
        /* only mark the cell as visited if the word was found
        else mark it as not visited
        mainly to overcome this problem of marking many "A"s as visited while one of them contains the solution already
        [["C","A","A"],["A","A","A"],["B","C","D"]] "AAB"
        */
        if(!exists) visited[row][col] = false;
        return exists;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        /*
        This problem can be solved using DFS
        it just reminds me of "Number Of Islands" prolem
        */
        
        if(word.length() == 0) return false;
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
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                visited[i][j] = false;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[order] && !visited[i][j]){
                    if(DFS(board, word, visited, order, i, j))
                        return true;
                }
            }
        }
        return false;
    }
};