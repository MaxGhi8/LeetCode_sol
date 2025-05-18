class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        # base case with only one column
        if n == 1:
            return 3 * (2 ** (m - 1))

        # initialize the dict
        D = {s: 1 for s in self.initialize(m)}

        # DP on columns
        for i in range(1, n):
            tmp = {}
            for k in D:
                for h in self.singleStep(m, k):
                    tmp[h] = (tmp.get(h, 0) + D[k]) % (10**9 + 7)
            D = tmp

        ans = 0
        for k in D:
            ans = (ans + D[k]) % (10**9 + 7)
        return ans

    @cache
    def singleStep(self, m: int, column: str) -> List:
        Ls = []
        for col in self.initialize(m):
            flag = 0
            for i in range(m):
                flag += int(col[i] == column[i])
            if flag == 0:
                Ls.append(col)
        return Ls

    @cache
    def initialize(self, m: int) -> List:
        Ls = ["r", "g", "b"]
        for _ in range(1, m):
            tmp = []
            for s in Ls:
                for char in "rgb":
                    if char != s[-1]:
                        t = s + char
                        tmp.append(t)
            Ls = tmp

        return Ls
