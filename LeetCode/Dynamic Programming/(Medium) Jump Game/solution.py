#time complexity O(n)
from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        current_end = 0
        farthest = 0
        
        for i in range(len(nums)):
            farthest = max(farthest, i + nums[i])
            if i == current_end:
                current_end = farthest
                
        return current_end >= len(nums) - 1

if __name__ == "__main__":
    nums = [3,2,1,0,4]
    solution = Solution()
    canjump = solution.canJump(nums)
    print(canjump)