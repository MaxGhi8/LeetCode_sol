from queue import Queue

class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:

        dist1 = self.BFS(edges, node1)
        dist2 = self.BFS(edges, node2)

        min_ = 10**9
        ans = -1
        for idx in range(len(edges)):
            i, j = dist1[idx], dist2[idx]
            d = max([i, j])
            if d < min_ and i != -1 and j != -1:
                min_ = d
                ans = idx

        return ans

    def BFS(self, edges, u):
        n = len(edges)
        dist = [-1]*n
        dist[u] = 0
        while dist[edges[u]] == -1:
            v = edges[u]
            if v == -1:
                break
            dist[v] = dist[u] + 1
            u = v
        
        return dist


        