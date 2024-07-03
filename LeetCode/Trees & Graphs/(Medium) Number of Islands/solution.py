from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        islands = 0
        visited = [[False for _ in range(cols)] for _ in range(rows)]

        def dfs(row: int, col: int):
            if row >= rows or col >= cols or row < 0 or col < 0 or visited[row][col]:
                return
            
            visited[row][col] = True

            if grid[row][col] == "0":
                return
            
            dfs(row + 1, col)
            dfs(row, col + 1)
            dfs(row - 1, col)
            dfs(row, col - 1)
    
        for row in range(rows):
            for col in range(cols):
                if not visited[row][col]:
                    visited[row][col] = True

                    if grid[row][col] == "1": 
                        islands += 1
                        dfs(row + 1, col)
                        dfs(row, col + 1)
        
        return islands

        
        