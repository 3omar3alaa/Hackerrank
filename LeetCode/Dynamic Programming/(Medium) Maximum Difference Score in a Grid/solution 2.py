'''
More straight forward solution is to start from top left cell and as we traverse we find the most min
value possible and calculate simultaneosly the highest difference
'''

from typing import List

class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        ans = float('-inf')
        rows = len(grid) # rows
        columns = len(grid[0]) # columns

        for row in range(rows):
            for col in range(columns):
                min_val = min(grid[row - 1][col] if row else float('inf'), grid[row][col - 1] if col else float('inf'))
                ans = max(ans, grid[row][col] - min_val)
                grid[row][col] = min(grid[row][col], min_val)
   
        return ans

if __name__ == "__main__":
    grid = [[9,5,7,3],[8,9,6,1],[6,7,14,3],[2,5,3,1]]
    solution = Solution()
    maxScore = solution.maxScore(grid)
    print(maxScore)