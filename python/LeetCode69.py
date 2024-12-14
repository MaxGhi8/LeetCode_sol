class Solution:
    def mySqrt(self, x: int) -> int:
        a = 0
        b = x
        if x == 1:
            return 1
        while True:
            c = floor((a + b) / 2)
            if c * c <= x:
                if (c + 1) * (c + 1) > x:
                    return c
                else:
                    a = c
            else:
                b = c
