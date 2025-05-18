class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # First solution O(n) complexity, O(1) space
        # D = {0:0, 1:0, 2:0}
        # for n in nums:
        #     D[n] += 1

        # for i in range(len(nums)):
        #     if i < D[0]:
        #         nums[i] = 0
        #     elif i < D[0] + D[1]:

        #         nums[i] = 1
        #     else:
        #         nums[i] = 2

        # Second solution, one pass algorithm with only constant extra space
        idx = [-1] * 3
        for i in range(len(nums)):
            n = nums[i]
            if n == 0:
                idx[0] += 1
                idx[1] += 1
                idx[2] += 1
                nums[idx[2]] = 2
                nums[idx[1]] = 1
                nums[idx[0]] = 0
            elif n == 1:
                idx[1] += 1
                idx[2] += 1
                nums[idx[2]] = 2
                nums[idx[1]] = 1
            else:
                idx[2] += 1
                nums[idx[2]] = 2
