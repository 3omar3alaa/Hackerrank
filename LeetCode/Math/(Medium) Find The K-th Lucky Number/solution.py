class Solution:
    def kthLuckyNumber(self, k: int) -> str:
        # the binary representation of kth lucky number is the binary representation of k+1
        k += 1
        result = ""
        while k > 1:
            if k & 1:
                result = "".join(("7", result))
            else:
                result = "".join(("4", result))
            k >>= 1
        return result