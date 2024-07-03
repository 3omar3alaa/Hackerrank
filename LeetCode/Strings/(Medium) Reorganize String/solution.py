class Solution:
    def reorganizeString(self, s: str) -> str:
        ans = [''] * len(s)
        counter = Counter(s)
        sorted_counter = dict(sorted(counter.items(), key=lambda item:item[1], reverse=True))
        # get the max freq
        first_char, first_freq = next(iter(sorted_counter.items()))

        if first_freq > ceil(len(s) / 2):
            return ''

        # put elements in even/odd spaces
        current_idx = 0
        for char, freq in sorted_counter.items():
            while freq > 0:
                if current_idx > len(s) - 1:
                    current_idx = 1
                ans[current_idx] = char
                current_idx += 2
                freq -= 1
        
        return ''.join(ans)

        