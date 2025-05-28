class Solution:
    def maxTargetNodes(
        self, edges1: List[List[int]], edges2: List[List[int]], k: int
    ) -> List[int]:
        m = len(edges2)
        n = len(edges1)
        edges1 = self.process_tree(edges1)
        edges2 = self.process_tree(edges2)

        if k == 0:
            return [1] * (n + 1)

        # process the second tree
        max_ = 0
        for i in range(m + 1):
            visited = set()
            visited.add(i)
            n_paths = self.DFS(edges2, visited, i, k - 1)
            if n_paths > max_:
                max_ = n_paths

        # process the first tree
        ans = [0] * (n + 1)
        for i in range(n + 1):
            visited = set()
            visited.add(i)
            ans[i] += self.DFS(edges1, visited, i, k) + max_

        return ans

    def process_tree(self, edges):
        tree = {}
        for edge in edges:
            start, end = edge[0], edge[1]
            tree[start] = tree.get(start, []) + [end]
            tree[end] = tree.get(end, []) + [start]

        return tree

    def DFS(self, tree, visited, u, k):
        # Routine that computes the number of nodes that I can reach
        # starting from start in at most k moves along the graph
        # defined by edges using DFS recursive algorithm
        for v in tree.get(u, []):
            if v not in visited and k >= 1:
                visited.add(v)
                self.DFS(tree, visited, v, k - 1)

        return len(visited)
