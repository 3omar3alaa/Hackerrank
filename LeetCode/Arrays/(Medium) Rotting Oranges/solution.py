class Solution:    
    def orangesRotting(self, grid: List[List[int]]) -> int:
        time = -1
        fresh = 0
        rows = len(grid)
        cols = len(grid[0])
        q = deque()

        # loop to get the index of the rotten orange
        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 2:
                    q.append((row, col))
                elif grid[row][col] == 1:
                    fresh += 1
        
        q.append((-1, -1))
        
        while q:
            row, col = q.popleft()

            if row == -1 and col == -1:
                time += 1
                # separator to know I have finished a level
                if q:
                    q.append((-1, -1))

            else:
                if row - 1 >= 0 and grid[row - 1][col] == 1: 
                    q.append([row - 1, col])
                    grid[row - 1][col] = 2
                    fresh -= 1
                
                if row + 1 < rows and grid[row + 1][col] == 1: 
                    q.append([row + 1, col])
                    grid[row + 1][col] = 2
                    fresh -= 1
                
                if col - 1 >= 0 and grid[row][col - 1] == 1: 
                    q.append([row, col - 1])
                    grid[row][col - 1] = 2
                    fresh -= 1
                
                if col + 1 < cols and grid[row][col + 1] == 1: 
                    q.append([row, col + 1])
                    grid[row][col + 1] = 2
                    fresh -= 1
            
        return time if fresh == 0 else -1
        
