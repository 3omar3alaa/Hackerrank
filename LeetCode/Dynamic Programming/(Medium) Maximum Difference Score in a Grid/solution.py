#Time limit exceeded -> this is Top Down Approach
# maybe i should try the Bottom Up approach

from typing import List

class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        rows = len(grid) # rows
        columns = len(grid[0]) # columns
        memo = [[0] * columns for _ in range(rows)]
        memo[rows -1][columns - 1] = 0

        def getScore(row: int, col: int):
            if row >= rows or col >= columns:
                return 0
            
            # the max score u get by starting at the right most bottom cel is zero
            elif row == rows - 1 and col == columns - 1:
                return 0

            if memo[row][col] != 0:
                return memo[row][col]
            
            max_score = float('-inf')

            # loop to the right
            for i in range(col + 1, columns):
                score = grid[row][i] - grid[row][col]
                # to check whether a signle move's score is bigger or I can make more moves
                # as some moves may yield negative scores and decrease the total score
                score = max(score, score + getScore(row, i))
                max_score = max(max_score,  score)
            
            # loop to the bottom
            for i in range(row + 1, rows):
                score = grid[i][col] - grid[row][col]
                # to check whether a signle move's score is bigger or I can make more moves
                # as some moves may yield negative scores and decrease the total score
                score = max(score, score + getScore(i, col))
                max_score = max(max_score, score)

            memo[row][col] = max_score
            return memo[row][col]
        
        getScore(0 , 0)
        # make the score of starting from the right most bottom cell is -inf to avoid choosing it -when it is 0-
        # if all other scores are negative
        memo[rows -1][columns - 1] = float('-inf')
        return max(max(r) for r in memo)


if __name__ == "__main__":
    grid = [[4,3,2],[3,2,1]]
    solution = Solution()
    maxScore = solution.maxScore(grid)
    print(maxScore)