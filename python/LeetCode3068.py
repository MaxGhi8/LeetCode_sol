class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        count = 0
        min_delta = 10**9
        ans = 0

        for i in range(len(nums)):
            n = nums[i]
            m = nums[i] ^ k
            delta = m - n

            if m > n:
                count = (count + 1) % 2
                ans += m
                if delta < min_delta:
                    min_delta = delta
            else:
                ans += n
                if -delta < min_delta:
                    min_delta = -delta

        return ans if count == 0 else ans - min_delta
