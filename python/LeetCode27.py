class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        ## This version is NOT optimized (due to the pop operation)
        # i = 0
        # count = 0
        # L = len(nums)
        # while i + count < L:
        #     if nums[i] == val:
        #         count += 1
        #         nums.pop(i)
        #     else:
        #         i += 1
        # return i

        ## This version is optimized (without pop operation)
        i = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i
