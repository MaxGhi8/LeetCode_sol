class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        # Construct a difference array
        n = len(nums)
        D = [0]*n
        D[0] = nums[0]
        for i in range(1, n):
            D[i] = nums[i] - nums[i-1]
        
        # Makes updates efficiently on the difference array (subctract numbers)
        for q in queries:
            D[q[0]] -= 1
            if q[1] + 1 < n:
                D[q[1]+1] += 1
        
        # Check the condition with prefix sum
        if D[0] > 0:
            return False

        for i in range(1, n):
            D[i] += D[i-1]
            if D[i] > 0:
                return False
        
        return True
