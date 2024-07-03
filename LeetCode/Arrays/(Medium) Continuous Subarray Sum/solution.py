class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        modIdxMap = defaultdict(int)
        prefixSum = 0
        # initialize the map with {0, -1} to tackle this test case
        # [23,2,4,6,6], k = 7
        modIdxMap[0] = -1
        for i, num in enumerate(nums):
            rem = (prefixSum + num) % k
            prefixSum += num
            if rem not in modIdxMap:
                modIdxMap[rem] = i

            elif rem in modIdxMap and i - modIdxMap[rem] > 1:
                return True
        return False
        