from collections import defaultdict


class Solution:
    def minimumKeypresses(self, s: str) -> int:
        # first of all find the char with highest frequency first
        alpha_count = {}
        alpha_freq = defaultdict(int)
        
        for char in s:
            alpha_freq[char] += 1
        
        sorted_alpha_freq = dict(sorted(alpha_freq.items(), key=lambda item: item[1], reverse=True))

        # store the number of presses required for each char
        for char in sorted_alpha_freq:
            dict_size = len(alpha_count)
            alpha_count[char] = (dict_size // 9 + 1)

        key_press = 0
        for char in s:
            key_press += alpha_count[char]

        return key_press