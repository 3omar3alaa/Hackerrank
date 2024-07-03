from typing import List


class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        # look back at max of length 10 as this is the max length of forbidden words
        forbidden_set = set(forbidden)
        res = 0
        right = 0
        left = 0
        for right in range(len(word)):
            for k in range(right, max(right - 10, left - 1), -1):
                if word[k:right + 1] in forbidden_set:
                    left = k + 1
                    break
            res = max(res, right - left + 1)

        return res
        