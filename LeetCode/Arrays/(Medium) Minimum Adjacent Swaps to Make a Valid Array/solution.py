class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        # faster solution

        swaps = 0
        max_element = max(nums)
        min_element = min(nums)

        # rightmost max index
        max_index = -1
        
        # leftmost min index
        min_index = -1

        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == max_element:
                max_index = i
                break

        for i in range(len(nums)):
            if nums[i] == min_element:
                min_index = i
                break
        
        swaps += (len(nums) - 1 - max_index)
        swaps += min_index

        if min_index > max_index:
            swaps -= 1

        return swaps