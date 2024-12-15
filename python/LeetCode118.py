import math


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        tot = []
        for i in range(numRows):
            tot.append(self.make_list(i))
        return tot

    def make_list(self, n):
        return [math.comb(n, i) for i in range(n + 1)]
