import math
from queue import Queue


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        return self.BFS(board, 0)

    def BFS(self, board: List[List[int]], start: int) -> int:
        n = len(board)
        visited = set()
        q = Queue()
        q.put(start)
        distance = [-1] * (n**2)
        distance[0] = 0

        # start BFS
        while not q.empty():
            u = q.get()
            visited.add(u)

            for v in self.diceMoves(u, n):
                # update with ladder
                if self.accesMatrix(v + 1, board) != -1:
                    v = self.accesMatrix(v + 1, board) - 1

                if v not in visited:
                    distance[v] = distance[u] + 1
                    q.put(v)
                    visited.add(v)

        return distance[-1]

    def accesMatrix(self, curr: int, board: List[List[int]]) -> int:
        # handle Boustrophedon style numbering
        n = len(board)
        q = math.floor((curr - 0.1) / n)
        r = (n - 1) - q
        if q % 2 == 0:
            c = (curr - 1) % n
        else:
            c = (n - 1) - ((curr - 1) % n)
        return board[r][c]

    def diceMoves(self, curr: int, n: int) -> List[int]:
        ans = []
        for i in range(1, 7):
            if curr + i <= n**2 - 1:
                ans.append(curr + i)
        return ans
