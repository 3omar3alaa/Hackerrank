class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Faster Solution
        for(int i = 0; i < 9; ++i) { //check rows
            vector<bool> rowCheck(9);
            vector<bool> colCheck(9);
            
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    if(rowCheck[board[i][j] - 1] == true) {
                        return false;
                    } else {
                        rowCheck[board[i][j] - 1] = true;
                    }
                }
                
                if(board[j][i] != '.') {
                  if(colCheck[board[j][i] - 1] == true) {
                    return false;
                    } else {
                        colCheck[board[j][i] - 1] = true;
                    }  
                }
            }
        }
        
        for(int k = 0; k < 3; ++k) {
            for(int l = 0; l < 3; ++l) {
               vector<bool> squareCheck(9);
                for(int i = 0; i < 3; ++i) {
                    for(int j = 0; j < 3; ++j) {
                       if(board[i+ 3*k][j+ 3*l] != '.') {
                           if(squareCheck[board[i+ 3*k][j+ 3*l] - 1] == true) {
                               return false;
                           } else {
                               squareCheck[board[i+3*k][j+ 3*l] - 1] = true;
                           }
                       } 
                    }
                } 
            } 
        }
        
        
        return true;
        /*
        vector<unordered_set<int>> rows(9, unordered_set<int>());
        vector<unordered_set<int>> columns(9, unordered_set<int>());
        vector<unordered_set<int>> boxes(9, unordered_set<int>());

        for (int i = 0; i < 9; ++i) {
          for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.')
              continue;

            int num = board[i][j] - '0';

            if (rows[i].count(num))
              return false;

            if (columns[j].count(num))
              return false;

            // This is a straight-forward math formula to locate a box
            // Out of the 9 boxes
            int box_index = (i / 3) * 3 + j / 3;

            if (boxes[box_index].count(num))
              return false;

            rows[i].insert(num);
            columns[j].insert(num);
            boxes[box_index].insert(num);
          }
        }

        return true;*/
        
    }
    
};