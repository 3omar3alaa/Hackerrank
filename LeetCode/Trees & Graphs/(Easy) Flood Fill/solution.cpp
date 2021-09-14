class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr, int sc, int color, int newColor){
        if(image[sr][sc] == color){
            image[sr][sc] = newColor;

            if(sr - 1 >= 0) DFS(image, sr - 1, sc, color, newColor);
            if(sc - 1 >= 0) DFS(image, sr, sc - 1, color, newColor);
            if(sr + 1 < image.size()) DFS(image, sr + 1, sc, color, newColor);
            if(sc + 1 < image[0].size()) DFS(image, sr, sc + 1, color, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Another solution using DFS
        int color = image[sr][sc];
        if(color != newColor)
            DFS(image, sr, sc, color, newColor);
        return image;
        
        /*
        // this is a BFS problem
        // make visited arr
        int row = image.size();
        int col = image[0].size();
        
        vector<vector<int>> visited (row , vector<int> (col));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                visited[i][j] = 0;
            }
        }
        
        // make queue to store neighbors
        queue<pair<int,int>> q;
        q.push({sr, sc});
        visited[sr][sc] = 1;
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){                
                pair<int, int> idx = q.front();
                q.pop();
                
                // check upper pair                
                if((idx.first - 1) >= 0 && !visited[idx.first - 1][idx.second] && image[idx.first][idx.second] == image[idx.first - 1][idx.second]){
                    q.push({idx.first - 1, idx.second});
                    visited[idx.first - 1][idx.second ] = 1;
                }
                
                // check left
                if((idx.second - 1) >= 0 && !visited[idx.first][idx.second - 1] && image[idx.first][idx.second] == image[idx.first][idx.second - 1]){
                    q.push({idx.first, idx.second - 1});
                    visited[idx.first][idx.second - 1] = 1;
                }
                
                
                // check right
                if((idx.second + 1) < col && !visited[idx.first][idx.second + 1] && image[idx.first][idx.second] == image[idx.first][idx.second + 1]){
                    q.push({idx.first, idx.second + 1});
                    visited[idx.first][idx.second + 1] = 1;
                }

                // check lower
                if((idx.first + 1) < row && !visited[idx.first + 1][idx.second] && image[idx.first][idx.second] == image[idx.first + 1][idx.second]){
                    q.push({idx.first + 1, idx.second});
                    visited[idx.first + 1][idx.second] = 1;
                }                
                
                image[idx.first][idx.second] = newColor;
            }
        }
        return image;*/
    }
};