class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        result = len(s)
        wordCount = {}
        extras = {}
        wordCount['Q'] = 0
        wordCount['W'] = 0
        wordCount['E'] = 0
        wordCount['R'] = 0
        
        for char in s:
            wordCount[char] += 1

        # get extras
        for char, val in wordCount.items():
            if val > n // 4:
                extras[char] = val - n // 4
        
        if not extras: return 0

        left = 0
        right = 0

        for right in range(n):
            if s[right] in extras:
                extras[s[right]] -= 1

            while max(extras.values()) <= 0:
                result = min(result, right - left + 1)
                if s[left] in extras:
                    extras[s[left]] += 1
                left += 1
                
        return result

        