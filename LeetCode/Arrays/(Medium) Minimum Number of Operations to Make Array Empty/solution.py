from typing import Counter, List


class Solution:
    def minOperations(self, nums: List[int]) -> int:
        counter = Counter(nums)
        result = 0
        print(counter.items())
        for element, freq in counter.items():
            if freq % 2 != 0 and freq % 3 != 0:
                # for freq like 13
                if freq > 3:
                    freq -= 3
                    result += 1
                    while(freq >= 0):
                        if freq % 3 == 0 :
                            result += freq // 3
                            break
                        else:
                            result += 1
                            freq -= 2

                else: return -1
            elif freq % 3 == 0:
                result += freq // 3
            
            elif freq % 2 == 0:
                # for freq like 10
                while(freq >= 0):
                    if(freq % 3 == 0):
                        result += freq // 3
                        break
                    else:
                        result += 1
                        freq -= 2


        return result
        