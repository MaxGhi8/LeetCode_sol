import heapq


class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])

        # Initialization
        cost = {}
        pq = [(0, 0, 0)]  # (cost, row, col)
        cost[(0, 0)] = 0
        visited = set()

        # Dijkstra alg.
        while pq:
            current_cost, row, col = heapq.heappop(pq)

            if (row, col) in visited:
                continue
            visited.add((row, col))

            if (row, col) == (n - 1, m - 1):
                return current_cost

            for dir in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                new_row = row + dir[0]
                new_col = col + dir[1]
                if 0 <= new_row < n and 0 <= new_col < m:
                    edge = max(1, moveTime[new_row][new_col] - current_cost + 1)

                    new_cost = current_cost + edge
                    if (new_row, new_col) not in cost or new_cost < cost[
                        (new_row, new_col)
                    ]:
                        cost[(new_row, new_col)] = new_cost
                        heapq.heappush(pq, (new_cost, new_row, new_col))

        return -1  # Should not reach here in a valid grid
