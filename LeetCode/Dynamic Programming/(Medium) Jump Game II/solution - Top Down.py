# time complexity O(n^2)
from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        memo = [float('inf')] * len(nums)

        def helper(idx : int):
            if idx >= len(nums) - 1: return 0

            if memo[idx] != float('inf'): return memo[idx]
            
            max_steps = max(nums[idx], 1)
            for i in range(1, max_steps + 1):
                memo[idx] = min(helper(idx + i) + 1, memo[idx])

            return memo[idx]
        
        return helper(0)
    
if __name__ == "__main__":
    nums = [3,2,1,0,4]
    solution = Solution()
    jumps = solution.jump(nums)
    print(solution.jump(nums))
