class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        # Difference array
        n = len(nums)
        D = [0] * n
        D[0] = nums[0]
        for i in range(1, n):
            D[i] = nums[i] - nums[i - 1]

        start = 0
        end = len(queries)
        mid = ceil((start + end) / 2)

        while (mid != start) and (mid != end):
            if self.checkQueries(mid, D.copy(), nums, queries):
                start = start
                end = mid
                mid = ceil((start + end) / 2)
            else:
                start = mid
                end = end
                mid = ceil((start + end) / 2)

        if self.checkQueries(start, D.copy(), nums, queries):
            return start
        elif self.checkQueries(end, D.copy(), nums, queries):
            return end
        else:
            return -1

    def checkQueries(self, mid: int, D, nums, queries) -> bool:
        for q in queries[:mid]:
            D = self.applyQuery(D, q)

        return self.checkZero(D, nums)

    def checkZero(self, D, nums) -> bool:
        nums[0] = D[0]
        if nums[0] > 0:
            return False
        for i in range(1, len(D)):
            nums[i] = D[i] + nums[i - 1]
            if nums[i] > 0:
                return False
        return True

    def applyQuery(self, D: List[int], q: List[int]) -> List[int]:
        # Function to apply a query to the difference array
        l, r, v = q[0], q[1], q[2]
        D[l] -= v
        if r + 1 < len(D):
            D[r + 1] += v
        return D
