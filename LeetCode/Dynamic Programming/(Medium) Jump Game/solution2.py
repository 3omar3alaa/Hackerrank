#time complexity O(n)
from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_reachable = 0
        for i in range(len(nums)):
            if i > max_reachable:
                return False
            max_reachable = max(max_reachable, i + nums[i])
        return True

if __name__ == "__main__":
    nums = [3,2,1,0,4]
    solution = Solution()
    canjump = solution.canJump(nums)
    print(canjump)