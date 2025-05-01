from functools import reduce

class Solution:
    def isHappy(self, n: int) -> bool:
        loop = {n}
        while True:
            n = reduce(lambda x, y: x + int(y)**2, str(n), 0)
            if n == 1:
                return True
            elif n in loop:
                return False
            else:
                loop.add(n)