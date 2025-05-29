class Solution:
    def maxTargetNodes(
        self, edges1: List[List[int]], edges2: List[List[int]]
    ) -> List[int]:
        m = len(edges2)
        n = len(edges1)
        edges1 = self.process_tree(edges1)
        edges2 = self.process_tree(edges2)

        # process the second tree
        visited_even = self.DFS(edges2, set(), set(), 0, 2)
        max_ = max([len(visited_even), m + 1 - len(visited_even)])

        # process the first tree
        visited = set()
        visited.add(0)
        visited_even = self.DFS(edges1, visited, set(), 0, 1)
        len_visited_even, len_visited_odd = len(visited_even), n + 1 - len(visited_even)

        ans = [0] * (n + 1)
        for i in range(n + 1):
            if i in visited_even:
                ans[i] = len_visited_even + max_
            else:
                ans[i] = len_visited_odd + max_

        return ans

    def process_tree(self, edges):
        tree = {}
        for edge in edges:
            start, end = edge[0], edge[1]
            tree[start] = tree.get(start, []) + [end]
            tree[end] = tree.get(end, []) + [start]

        return tree

    def DFS(self, tree, visited_even, visited_odd, u, k):
        # Routine that compute all the reachable even nodes starting from a given node
        for v in tree.get(u, []):
            if v not in visited_even and v not in visited_odd:
                if k % 2 == 0:
                    visited_even.add(v)
                else:
                    visited_odd.add(v)
                self.DFS(tree, visited_even, visited_odd, v, k + 1)

        return visited_even
