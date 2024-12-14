import math


class Solution:
    def climbStairs(self, n: int) -> int:
        num_max_2 = n // 2
        rem = n % 2
        tot = 0
        for i_2 in range(num_max_2 + 1):
            tot += math.comb(i_2 + (num_max_2 - i_2) * 2 + rem, i_2)
        return tot
