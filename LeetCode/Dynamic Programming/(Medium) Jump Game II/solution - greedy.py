# time complexity O(n)
from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps = 0
        current_end = 0
        farthest = 0
        
        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])
            if i == current_end:
                jumps += 1
                current_end = farthest
                
        return jumps
    
if __name__ == "__main__":
    nums = [3,2,1,0,4]
    solution = Solution()
    jump = solution.jump(nums)
    print(jump)