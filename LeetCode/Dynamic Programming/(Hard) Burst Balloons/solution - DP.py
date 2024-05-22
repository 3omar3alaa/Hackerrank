# time complexity: O(n^3)
from typing import List

'''
Consider the i in the for loop to be the last balloon to be burst, so in order for it to be the 
last balloon to be burst we find the sum of left and right sub arrays that were burst before and find the coins
'''
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        # Add 1 before and after nums array to handle the edge cases easily
        nums = [1] + nums + [1]

        n = len(nums)
         # Create a memoization table
        memo = [[0] * n for _ in range(n)]


        def burst(left, right):
            # Base case: no more balloons to burst
            if left + 1 == right:
                return 0

            if memo[left][right] > 0:
                return memo[left][right]
            
            max_coins = 0
            # Try bursting each balloon in the range (left, right)
            for i in range(left + 1, right):
                # Calculate coins obtained by bursting balloon i
                coins = nums[left] * nums[i] * nums[right]
                # Recursively burst the remaining balloons
                coins += burst(left, i) + burst(i, right)
                # Update the maximum coins obtained
                max_coins = max(max_coins, coins)

            memo[left][right] = max_coins
            return max_coins

        # Initial call with the full range of the original array indices
        return burst(0, len(nums) - 1)

# Example usage
if __name__ == "__main__":
    nums = [3, 1, 5, 8]
    solution = Solution()
    print(solution.maxCoins(nums))  # Output: 167
