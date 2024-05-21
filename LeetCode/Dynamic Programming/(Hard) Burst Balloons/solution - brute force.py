from typing import List

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
                # Recursive helper function to calculate maximum coins
        def burst(balloons):
            # Base case: no more balloons to burst
            if not balloons:
                return 0

            # Add 1 before and after nums array to handle the edge cases easily
            nums = [1] + balloons + [1]
            max_coins = 0
            # Try bursting each balloon and calculate the coins
            for i in range(len(balloons)):
                # coins = nums[balloons[i] - 1] * nums[balloons[i]] * nums[balloons[i] + 1]
                coins = nums[i] * nums[i + 1] * nums[i + 2]
                remaining_balloons = balloons[:i] + balloons[i + 1:]
                coins += burst(remaining_balloons)
                max_coins = max(max_coins, coins)

            return max_coins

        # Initial call with all balloon indices
        return burst(nums)

# Example usage
if __name__ == "__main__":
    nums = [3, 1, 5, 8]
    solution = Solution()
    print(solution.maxCoins(nums))  # Output: 167
