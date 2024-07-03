from collections import defaultdict
from itertools import combinations
from typing import List


class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        # includes user data for websites visited by each user
        user_data = defaultdict(list)

        for u,t,w in zip(username, timestamp, website):
            user_data[u].append((t , w))

        for user in user_data:
            user_data[user].sort()

        print(user_data)
        # include three sequence combination by each user
        user_sequence = defaultdict(set)

        for user, visits in user_data.items():
            websites = [website for timestamp, website in visits]
            
            for combo in combinations(websites, 3):
                user_sequence[combo].add(user)

        print(user_sequence)
        # count occurence of each sequence
        count_sequence = defaultdict(list)

        for sequence, users in user_sequence.items():
            count_sequence[sequence] = len(users)

        # get the max count
        max_count = 0
        result_sequence = None
        for sequence, count in count_sequence.items():
            if count > max_count or (count == max_count and  sequence < result_sequence):
                max_count = count
                result_sequence = sequence
        
        return result_sequence
