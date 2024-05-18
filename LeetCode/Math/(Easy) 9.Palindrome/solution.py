class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x != 0): return False

        # compare the first half to the other half
        half_num = 0
        while half_num < x:
            half_num = half_num*10 + x %10 
            x //=10
 
        return x == half_num or x == half_num // 10

        