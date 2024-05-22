class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [0] * (n + 1)

        def recursive(n : int):
            if n < 0: return 0
            if n == 0 or n == 1: return 1

            if memo[n] > 0: return memo[n]

            memo[n] = recursive(n - 1) + recursive(n - 2)

            return memo[n]

        return recursive(n)
        