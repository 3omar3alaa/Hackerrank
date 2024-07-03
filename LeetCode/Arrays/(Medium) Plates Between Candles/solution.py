from typing import List


class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        prefixPlates = [0] * n
        leftCandles = [-1] * n
        rightCandles = [-1] * n

        # fill the number of plates 
        plates = 0
        for i, char in enumerate(s):
            if char == '*':
                plates += 1
            prefixPlates[i] = plates
        
        # fill the leftCandle
        idx = -1
        for i, char in enumerate(s):
            if char == '|':
                idx = i
            leftCandles[i] = idx

        
        # fill the rightCandle
        idx = -1
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '|':
                idx = i
            rightCandles[i] = idx

        print(prefixPlates)
        print(leftCandles)
        print(rightCandles)
        result = []
        for query in queries:
            if leftCandles[query[1]] <= rightCandles[query[0]] or query[0] == query[1]:
                result.append(0)
            else:
                rightMostCandle = leftCandles[query[1]]
                leftMostCandle = rightCandles[query[0]]
                result.append(prefixPlates[rightMostCandle] - prefixPlates[leftMostCandle])
        return result
