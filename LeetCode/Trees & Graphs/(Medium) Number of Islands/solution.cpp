class Solution {
public:
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        if(!visited[row][col] && grid[row][col] == '1'){
            visited[row][col] = true;
            if(row - 1 >= 0) DFS(grid, visited, row - 1, col);
            if(col - 1 >= 0) DFS(grid, visited, row, col - 1);
            if(row + 1 < grid.size()) DFS(grid, visited, row + 1, col);
            if(col + 1 < grid[0].size()) DFS(grid, visited, row, col + 1);            
        }
    }
    
    void DFS(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '0';
        if(row - 1 >= 0 && grid[row - 1][col] == '1') DFS(grid, row - 1, col);
        if(col - 1 >= 0 && grid[row][col - 1] == '1') DFS(grid, row, col - 1);
        if(row + 1 < grid.size() && grid[row + 1][col] == '1') DFS(grid, row + 1, col);
        if(col + 1 < grid[0].size() && grid[row][col + 1] == '1') DFS(grid, row, col + 1);            
    }
    
    int numIslands(vector<vector<char>>& grid) {
        /*
        This porblem can be solved in either DFS or BFS
        however I see it's more obvious to solve in BFS
        
        BFS steps
        1- make 2d vector to hold visited points
        2- loop over the grid vector
        3- make a queue and add each adjacent element to the queue if it is 1
        4- when the queue is empty then i have an island
        5- continue the outer loop over non visited points
        6- return number of loops
        
        DFS steps
        1- make 2d vector to hold visited points
        2- loop over the grid vector
        3- if point is not visited and is land then DFS it
        4- loop over its neighbors recursively and update visited list
        or simply make the grid = 0 
        5- after DFS is done, increment islands count
        */
        
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<bool>> visited (n, vector<bool> (m));
        
        // initialize the visited arr
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                visited[i][j] = false;
            }
        }*/
        
        // loop over the grid array
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                /*if(grid[i][j] == '1' && !visited[i][j]){
                    DFS(grid, visited, i, j);
                    islands++;
                }*/
                
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};