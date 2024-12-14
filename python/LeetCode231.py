class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False
        while n != 1:
            if abs(n / 2 - n // 2) < 0.1:
                n = n // 2
            else:
                return False
        return True
