class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        n = len(deck)
        result = [-1] * n
        resultIdx = 0
        deckIdx = 0
        skip = False
        round = 0

        while deckIdx < n:   
            if result[resultIdx] == -1:

                if not skip:
                    result[resultIdx] = deck[deckIdx]
                    deckIdx += 1
                
                skip = not skip

            resultIdx = (resultIdx + 1) % n
        
        return result

