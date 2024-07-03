from collections import Counter


class Solution:
    def minimumKeypresses(self, s: str) -> int:
        count = Counter(s)
        ans = 0
        level = 0

        for i, freq in enumerate(sorted(count.values(), reverse = True)):
            # always take batches of 9
            if i % 9 == 0:
                level += 1
            ans += level * freq
        
        return ans